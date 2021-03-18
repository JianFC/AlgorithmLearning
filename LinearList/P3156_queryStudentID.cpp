#include <iostream>
#include <algorithm>
#include <conio.h>
#define fp(i, l ,r) for(register int i=(l); i<=(r); i++) 
#define fd(i, l ,r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 2*1e6+5;
const int maxm = 1e5+5;
int id[maxn] = {0};
int n, m;
int query[maxm] = {0};

int main(void) {
    cin >> n >> m;
    fp(i, 1, n) cin >> id[i];
    fp(i, 1, m) cin >> query[i];
    fp(i, 1, m) cout << id[query[i]] << endl;

    _getch();
    return 0;
}