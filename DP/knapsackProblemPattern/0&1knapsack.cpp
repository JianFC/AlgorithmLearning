// 0&1背包问题
// 有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
// 第 i 件物品的体积是 vi，价值是 wi 。
// 求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。 输出最大价值。
// 输入格式
// 第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
// 接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。
// 输出格式
// 输出一个整数，表示最大价值。
// 数据范围
// 0<N,V≤10000 0<vi,wi≤10000
// 输入样例
// 4 5
// 1 2
// 2 4
// 3 4
// 4 5
// 输出样例：
// 8

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
const int maxn = 1e4+5;
const int maxv = 1e4+5;
int n, v;   
int dp[maxn][maxv] = {0};     //dp[i][j]表示从前i件物品中选出物品恰好放入容量为j的背包所能取得的最大价值
int V[maxn] = {0};  //V[i]表示第i件物品的体积
int W[maxn] = {0};  //W[i]表示第i件物品的价值
int res = 0;
int dp2[maxv] = {0};    //优化空间复杂度 
int res2 = 0;

// 常规方法， 时间复杂度与空间复杂度为O(nxv);
void method_1 (void) {
    fp(i, 1, n) {
        fp(j, 1, v) {
            if (j<V[i]) dp[i][j] = dp[i-1][j];
            else {
                // 状态转移方程
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-V[i]]+W[i]);
            }
        }
    }
}

// 优化方法，空间复杂度为O(n),时间复杂度为O(nxv);
void method_2 (void) {
    fp(i, 1, n) {
        fd(j, v, 1) {
            if (j<V[i]) dp2[j] = dp2[j];
            else {
                dp2[j] = max(dp2[j], dp2[j-V[i]]+W[i]);
            }
        }
    }
}


int main(void) {
    cin >> n >> v;
    fp(i, 1, n) cin >> V[i] >> W[i];
    method_1();
    method_2();
    fp(j, 1, v) res = max(res, dp[n][j]);
    fp(j, 1, v) res2 = max(res2, dp2[j]);
    cout << res << " " << res2;

    _getch();
    return 0;
}