#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main(void) {    //AcWing 3. 完全背包问题，朴素版超时
    scanf("%d%d", &n, &m);

    for (int i=1; i<=n; i++) scanf("%d%d", &v[i], &w[i]);

    for (int i=1; i<=n; i++)
        for (int j=0; j<=m; j++)
            for (int k=0; k*v[i]<=j; k++)   //依据选i的个数，划分为k个子集
                f[i][j] = max(f[i][j], f[i-1][j-k*v[i]]+k*w[i]);

    cout << f[n][m];

    return 0;
}