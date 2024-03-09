// 完全背包问题
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
const int maxt = 1e7+5;
const int maxm = 1e4+5;
long long dp[maxt] = {0};
int m, t;
int T[maxm] = {0};
int W[maxm] = {0};
long long res = 0;

int main(void) {
    cin >> t >> m;
    fp(i, 1, m) cin >> T[i] >> W[i];
    // 10^7x10^4 = 10^11,极限情况下int溢出，故需要开long long数组
    fp(i, 1, m) {
        fp(j, 1, t) {
            if (j < T[i]) dp[j] = dp[j];
            else {
                dp[j] = max(dp[j], dp[j-T[i]]+W[i]);
            }
        }
    }

    fp(j, 1, t) res = max(res, dp[j]);
    cout << res;

    _getch();
    return 0;
}