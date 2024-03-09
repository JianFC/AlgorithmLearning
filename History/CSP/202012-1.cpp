#include <iostream>
#include <cstdio>
#include <algorithm>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn =1e5+5;
int n;
ll res = 0;
ll w, score;
ll zero = 0;

int main(void) {
    cin  >> n;
    fp(i, 1, n) {
        cin >> w >> score;
        res += w*score;
    }
    cout << max(zero, res);

    _getch();
    return 0;
}