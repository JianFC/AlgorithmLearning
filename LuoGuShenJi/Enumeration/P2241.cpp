#include <iostream>
#include <algorithm>
#include <conio.h>
#include <math.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;   //不开ll见祖宗qwq

using namespace std;

int main(void) {
    ll n, m, rec = 0, squ = 0;
    cin >> n >> m;
    // 枚举边长
    for (int i=1; i<=min(n, m); i++) {
        squ += (n-i+1)*(m-i+1);
    }
    rec = n*(n+1)*m*(m+1)/4 - squ;
    cout << squ << " " << rec;

    _getch();
    return 0;
}
