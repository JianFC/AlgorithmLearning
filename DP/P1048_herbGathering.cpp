#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
const int maxt = 1e4+5;
const int maxm = 110;
int dp[maxt] = {0};
int m, t;
int T[maxm] = {0};  //T[i]代表采摘第i株药草的时间
int W[maxm] = {0};  //W[i]代表采摘第i株药草的价值
int res = 0;

int main(void) {
    cin >> t >> m;
    fp(i, 1, m) cin >> T[i] >> W[i];
    fp(i, 1, m) {
        fd(j, t, 1) {
            if (j<T[i]) dp[j] = dp[j];
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