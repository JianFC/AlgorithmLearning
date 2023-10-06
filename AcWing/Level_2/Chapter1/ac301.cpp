#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //301. 任务安排2

typedef long long LL;   //数据会爆int

const int N = 300010;

int n, s;
LL c[N], t[N];     //c表示原c的前缀和，t表示原t的前缀和
LL f[N];   //f[i]表示将所有1-i任务处理完的分批方案的费用最小值
int q[N];   //维护f[i]和c[i]所构成的凸包，存储下标，初始时f[0]在队列中

int main() {
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld%lld", &t[i], &c[i]);
        t[i] += t[i - 1];   //维护前缀和
        c[i] += c[i - 1];
    }
    
    int hh = 0, tt = 0;     //初始时一个元素
    q[0] = 0;
    //时间复杂度O(n)
    for (int i = 1; i <= n; i ++) {
        //查询前维护队列，除法操作变乘法，避免精度问题，且保证队列中至少有两个元素
        while (hh < tt && (f[q[hh + 1]] - f[q[hh]]) <= (t[i] + s) * (c[q[hh + 1]] - c[q[hh]])) hh ++;
        
        int j = q[hh];  //去除队头元素
        f[i] = f[j] - (t[i] + s) * c[j] + t[i] * c[i] + s * c[n];   //更新f[i]
        
        //插入前维护队列，除法变乘法
        while (hh < tt && (f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt]]) >= (f[i] - f[q[tt]]) * (c[q[tt]] - c[q[tt - 1]])) tt --;
        q[++ tt] = i;   //第i个点入队
    }
    
    printf("%lld\n", f[n]);
         
    
    return 0;
}