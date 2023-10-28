#include <iostream>
#include <algorithm>

using namespace std;    //AcWing 1018. 最低通行费

const int N = 110, INF = 2e9;

int n;
int w[N][N];    //存储矩阵
int f[N][N];    //DP数组

int main() {    
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) scanf("%d", &w[i][j]);

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) {
            if (i == 1 && j == 1) f[i][j] = w[i][j];    //特判左上角
            else {
                f[i][j] = INF;      //求最小值需要初始化
                //不是第一行，i > 1时可从上往下
                if (i > 1) f[i][j] = min(f[i][j], f[i - 1][j] + w[i][j]);
                //不是第一列，j > 1时可从左往右   
                if (j > 1) f[i][j] = min(f[i][j], f[i][j - 1] + w[i][j]);   
            }
        }

    printf("%d\n", f[n][n]);

    return 0;
}