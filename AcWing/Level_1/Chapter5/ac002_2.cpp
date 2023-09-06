#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];     //v[i]表示第i件物品的体积，w[i]表示第i物品的价值
int f[N];    

int main(void) {    //AcWing 2. 01背包问题降维优化
    scanf("%d%d", &n, &m);

    //根据题意，从1开始输入
    for (int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);

    //根据实际意义f[0][0~m] = 0，全局变量默认为0，所以从1开始
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            //若从小向大遍历，则该方程等价与f[i][j] = max(f[i][j], f[i][j-v[i]]+w[i])
            //所以应该从大到小遍历
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}
