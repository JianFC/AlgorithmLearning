#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //302. 任务安排3

typedef long long LL;

const int N = 300010;

int n, s;
LL t[N], c[N];      //t代表原t的前缀和数组，c代表原c的前缀和数组
LL f[N];    //f[i]代表将1 - i任务完成的所有分批方案的费用最小值
int q[N];   //维护凸包下边界的队列，存储下标

int main() {
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld%lld", &t[i], &c[i]);
        t[i] += t[i - 1];   //前缀和
        c[i] += c[i - 1]; 
    }

    int hh = 0, tt = 0;     //初始时(c[0], f[0])在队列中
    
    for (int i = 1; i <= n; i ++) {     //枚举每个数
        //二分队列中第一个斜率大于(t[i] + s)的点
        int l = hh, r = tt;     //二分的左右边界
        while (l < r) {     //二分右区间中答案
            int mid = l + r >> 1;
            if ((f[q[mid + 1]] - f[q[mid]]) > (t[i] + s) * (c[q[mid + 1]] - c[q[mid]])) r = mid;
            else l = mid + 1;
        }
        
        int j = q[l];      //第一个满足要求的点
        f[i] = f[j] - (t[i] + s) * c[j] + t[i] * c[i] + s * c[n];   //转移方程
        //插入前维护队列，和上题一致，注意方括号层级，转换为double，防止溢出long long
        while (hh < tt && (__int128)(f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt]]) >= (__int128)(f[i] - f[q[tt]]) * (c[q[tt]] - c[q[tt - 1]])) tt --;
        q[++ tt] = i;   //插入(c[i], f[i])
    }
    
    printf("%lld\n", f[n]);
    
    return 0;
}