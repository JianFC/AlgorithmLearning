//01背包问题变式
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1e3+5;
const int maxx = 1e3+5;
ll dp[maxn][maxx] = {0};
int lose[maxn], win[maxn], use[maxn];   //lose[i]输掉得到的exp，win[i]赢得到的exp，use[i]使用的药剂数
int n, x;
ll res = 0;

int main(void) {
    cin >> n >> x;
    fp(i, 1, n) cin >> lose[i] >> win[i] >> use[i];
    fp(i, 1, n) {
        fp(j, 0, x) {
            if (j<use[i]) dp[i][j] = dp[i-1][j] + lose[i];
            else {
                //状态转移方程，可以优化为1维数组，详见背包问题模板
                dp[i][j] = max(dp[i-1][j]+lose[i], dp[i-1][j-use[i]]+win[i]);
            }
        }
    }

    fp(j, 0, x) res = max(res, dp[n][j]);
    cout << res*5;

    _getch();
    return 0;
}