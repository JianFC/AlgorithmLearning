#include <iostream>
#include <algorithm>

using namespace std;        //AcWing 1015. 摘花生

const int N = 110;

int n, m;
int w[N][N];        //存储矩阵
int f[N][N];        //DP数组

int main() {    
    int T; 
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++) scanf("%d", &w[i][j]);

        for (int i = 1; i <= n; i ++)    //注意下标起始位置
            for (int j = 1; j <= m; j ++)
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];  //状态转移方程

        printf("%d\n", f[n][m]);
    }

    return 0;
}