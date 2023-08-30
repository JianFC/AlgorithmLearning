#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, INF = 2e9;

int n;
int w[N][N];
int f[N][N];

int main() {    //AcWing 1018. 最低通行费
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) scanf("%d", &w[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) f[i][j] = w[i][j]; //特判左上角
            else {
                f[i][j] = INF;
                if (i > 1) f[i][j] = min(f[i][j], f[i - 1][j] + w[i][j]);   //i>1时可从上往下
                if (j > 1) f[i][j] = min(f[i][j], f[i][j - 1] + w[i][j]);   //j>1时可从左往右
            }
        }

    printf("%d\n", f[n][n]);

    return 0;
}