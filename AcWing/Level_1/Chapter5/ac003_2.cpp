#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main(void) {    //AcWing 3. 完全背包问题优化时间复杂度
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) scanf("%d%d", &v[i], &w[i]);

    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= m; j ++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }

    cout << f[n][m];

    return 0;
}