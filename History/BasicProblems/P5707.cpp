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
    int s, v;
    cin >> s >> v;
    int t = ceil((float)s/v+10);
    int h = t/60, m = t%60;
    
    int res_m = 0, res_h = 0;
    if (m!=0) {res_m = 60-m; h=h+1;}
    
    if (8-h<0) res_h = 24+(8-h);    //注意8-h是负数
    else res_h = 8-h;
    
    if (res_h<10) cout << 0 << res_h << ":";
    else cout << res_h << ":";
    if (res_m<10) cout << 0 << res_m;
    else cout << res_m;
    
    _getch();
    return 0;
}