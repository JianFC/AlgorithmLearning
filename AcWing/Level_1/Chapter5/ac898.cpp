#include <iostream>

using namespace std;

const int N = 510, INF = 1e9;;

int n;
int a[N][N];
int f[N][N];    //f[i][j]表示从起点走到(i, j)所有路径权值之和的最大值

int main(void) {    //AcWing 898. 数字三角形
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);

    //初始化f[i][j], 以处理边界情况
    //注意每行左边界往左与右边界往右各应多初始化一个位置,下一层会用到这两个位置
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i + 1; j++)
            f[i][j] = -INF;

    //初始化dp初始边界
    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            //状态转移方程
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);

    //在最后一层寻找最大值作为答案
    int res = -INF;
    for (int i = 1; i <= n; i++) res = max(res, f[n][i]);

    cout << res;

    return 0;
}