#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main(void) {    //AcWing 3. 完全背包问题优化时间复杂度和空间复杂度
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)     //从小到大循环，与01背包唯一区别
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m];

    return 0;
}