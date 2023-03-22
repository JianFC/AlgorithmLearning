#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
int r, y, g;
int n;
int k, t;
int res = 0;

int main(void) {
    cin >> r >> y >> g;
    cin >> n;
    fp(i, 1, n) {
        cin >> k >> t;
        switch(k){
            case 0: res += t; break;
            case 1: res += t; break;
            case 2: res = res + t + r; break;
        }
    }
    cout << res;
    

    _getch();
    return 0;
}