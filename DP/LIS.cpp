#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <conio.h>

using namespace std;
const int maxn = 1e3 + 10;

int main(void) {
    int a[maxn];
    int maxlen[maxn];
    int res = -0x0f0f0f0f;
    memset(a, 0, sizeof(a));
    memset(maxlen, 0, sizeof(maxlen));
    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        maxlen[i] = 1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            if (a[i] > a[j]) {
                //状态转移方程 maxlen(ak) = max{maxlen(ai)+1, maxlen(ak)}
                //or maxlen(ak) = max{maxlen(ai), 1<=i<k, ai<ak, k≠1}+1
                maxlen[i] = max(maxlen[i], maxlen[j]+1);  
            }
        }
        cout << maxlen[i] << " ";
        res = max(res, maxlen[i]);
    }
    cout << endl << res;
    _getch();
    return 0;
}