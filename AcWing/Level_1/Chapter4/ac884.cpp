#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int a[N][N];

int gauss() {   //AcWing 884. 高斯消元解异或线性方程组
    int c, r;

    for (c = 0, r = 0; c < n; c++) {
        int t = r;

        for (int i = r; i < n; i++)
            if (a[i][c]) {
                t = i;
                break;
            }

        if (a[t][c] == 0) continue;

        for (int i = 0; i < n + 1; i++) swap(a[t][i], a[r][i]);

        for (int i = r + 1; i < n; i++)
            if (a[i][c])  
                for (int j = n; j >= c; j--)
                    a[i][j] ^= a[r][j];     
        r++;
    }

    if (r < n) {
        for (int i = r; i < n; i++)
            if (a[r][n])
                return 2;

        return 1;
    }

    for (int i = n - 1; ~i; i--)
        for (int j = i + 1; j<n; j++)
            //对非主元的每一项a[i][j]*a[j][n]，等式两边同时^a[i][j]*a[j][n]
            //从而将该项消零
            a[i][n] ^= a[i][j] * a[j][n];

    return 0;
}

int main(void) {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j< n + 1; j++)
            scanf("%d", &a[i][j]);

    int t = gauss();

    if (!t)
        for (int i = 0; i < n; i++) printf("%d\n", a[i][n]);
    else if (t == 1) puts("Multiple sets of solutions");
    else puts("No solution");

    return 0;
}