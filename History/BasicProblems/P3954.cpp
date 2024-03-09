#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    int res = a*0.2 + b*0.3 + c*0.5;
    cout << res;

    _getch();
    return 0;
}