#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1087. 修剪草坪

typedef long long LL;   //前缀和可能爆int

const int N = 100010;

int n, m;
LL s[N];    //前缀和数组
LL f[N];    //f[i]表示所有从前i头牛中选，且合法的所有方案的效率最大值
int q[N];   //单调队列

LL g(int i) {
    if (!i) return 0;   //当i == 0时，边界情况，直接返回0
    return f[i - 1] - s[i];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }
    
    int hh = 0, tt = 0;     //初始时g(0)存在于单调队列中
    for (int i = 1; i <= n; i ++) {
        if (q[hh] < i - m) hh ++;   //i前面最多有m个数
        f[i] = max(f[i - 1], g(q[hh]) + s[i]);      //状态转移方程
        while (hh <= tt && g(q[tt]) <= g(i)) tt --;     //维护单调队列性质
        q[++ tt] = i;   //入队
    }
    
    printf("%lld\n", f[n]);
    
    return 0;
}