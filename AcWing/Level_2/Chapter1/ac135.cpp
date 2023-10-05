#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //135. 最大子序和

const int N = 300010, INF = -2147483648;

int n, m;
int s[N], q[N];     //s表示前缀和数组，q表示单调队列数组

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) {     //前缀和要求从1开始
        scanf("%d", &s[i]);
        s[i] += s[i - 1];   //预处理前缀和
    }
    
    int res = -INF;         //存储答案
    int hh = 0, tt = 0;     //一开始s[0]存在于队列中，所以tt = 0
    for (int i = 1; i <= n; i ++) {     //从前往后枚举每个数
        if (hh <= tt && q[hh] < i - m) hh ++;   //q中保存的是前缀和数组下标，需要用到i - m + 1前一个数，所以不加1
        res = max(res, s[i] - s[q[hh]]);        //更新以a[i]结尾的长度不超过m的子序列的最大和
        while (hh <= tt && s[q[tt]] >= s[i]) tt --;     //使单调队列中的前缀和s[i]满足递增关系
        q[++ tt] = i;    //s[i]入队，注意单调队列存储下标
    }
    
    printf("%d\n", res);
    
    return 0;
}