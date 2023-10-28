#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1088. 旅行问题

typedef long long LL;

const int N = 200010;   // 破环成链，多开一倍空间

int n;
int o[N], d[N];     //o[i]，d[i]分别表示第i站的油量和到下一站的距离
LL s[N];    //s[i]表示o[i] - d[i] or o[i] - d[i - 1]的前缀和
int q[N];   //单调队列
bool ans[N];        //存储i点是否可以顺时针or逆时针走完一圈

int main() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++) scanf("%d%d", &o[i], &d[i]);
    
    //顺时针做
    for (int i = 1; i <= n; i ++) s[i] = s[i + n] = o[i] - d[i];    //破环成链
    for (int i = 1; i <= n * 2; i ++) s[i] += s[i - 1];     //处理前缀和，注意前缀和的区间长度
    
    int hh = 0, tt = -1;    //初始时单调队列中没有元素
    for (int i = n * 2; i; i --) {      //从[i, i + n - 1]中找出前缀和最小值，对于i，依赖其后的n个元素，从大到小遍历
        if (hh <= tt && q[hh] > i + n - 1) hh ++;   //找到[i, i + n - 1]中前缀和的最小值，维护单调队列区间
        
        while (hh <= tt && s[q[tt]] >= s[i]) tt --;     //需要i的信息，所以先将i插入单调递增队列中
        q[++ tt] = i;
        
        if (i <= n && s[q[hh]] >= s[i - 1]) ans[i] = true;  //即s[q[hh]] - s[i - 1] >= 0，该点合法
    }
    
    //逆时针做
    d[0] = d[n];    //令s[i]为o[i] - d[i - 1]的前缀和，所以需要特殊处理d[0]点，即从1号点可以走到n号点
    for (int i = 1; i <= n; i ++) s[i] = s[i + n] = o[i] - d[i - 1];
    for (int i = 1; i <= n * 2; i ++) s[i] += s[i - 1];     //处理前缀和
    
    hh = 0, tt = -1;
    for (int i = 1; i <= n * 2; i ++) {     //对于点i，从[i - n, i - 1]中找出前缀的最大值，点i依赖其前n个元素，从小到大遍历
        if (hh <= tt && q[hh] < i - n) hh ++;   //区间为[i - n, i - 1]，维护左区间
        
        if (i > n && s[q[hh]] <= s[i]) ans[i - n] = true;   //即s[i] - s[q[hh]] >= 0，则i - n点合法，由反向前缀和定义而来
        
        while (hh <= tt && s[q[tt]] <= s[i]) tt --;     //不需要i的信息，维护单调递减队列
        q[++ tt] = i;
    }
    
    //输出答案
    for (int i = 1; i <= n; i ++)
        if (ans[i]) puts("TAK");
        else puts("NIE");
    
    return 0;
}
