#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];     //v[i]表示第i件物品的体积，w[i]表示第i物品的价值
int f[N][N];    //f[i][j]表示分析中满足i,j限制条件集合的最大值属性

int main(void) {        //AcWing 2. 01背包问题朴素版
    scanf("%d%d", &n, &m);

    //根据题意，从1开始输入
    for (int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);

    //根据实际意义f[0][0 ~ m] = 0，全局变量默认为0，所以从1开始
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= m; j ++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }

    cout << f[n][m] << endl;

    return 0;
}