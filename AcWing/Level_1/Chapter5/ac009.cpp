#include <iostream>

using namespace std;            //AcWing 9. 分组背包问题

const int N = 110;

int n, m;
int v[N][N], w[N][N], s[N];
int f[N];

int main(void) {    
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) {
        scanf("%d", &s[i]);
        for (int j = 0; j < s[i]; j ++)
            scanf("%d%d", &v[i][j], &w[i][j]);
    }

    for (int i = 1; i <= n; i ++)
        for (int j = m; j >= 0; j --)
            //若不选，则降维后f[j] = f[j]，此处省略不写
            for (int k = 0; k < s[i]; k ++) //枚举选第i组中哪一个
                if (j >= v[i][k]) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    cout << f[m] << endl;

    return 0;
}