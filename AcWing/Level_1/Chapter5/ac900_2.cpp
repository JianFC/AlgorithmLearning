#include <iostream>
#include <algorithm>

using namespace std;        //AcWing 900. 整数划分

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N][N];    //f[i][j]表示总和是i，且恰好表示为j个数和的方案集合中元素数量

int main(void) {
    scanf("%d", &n);

    f[0][0] = 1;    //总和是0，由0个数构成，方案数是1

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            //状态转移方程
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;

    //枚举求和得答案
    int res = 0;
    for (int i = 1; i <= n; i ++) res = (res + f[n][i]) % mod;

    cout << res;

    return 0;
}