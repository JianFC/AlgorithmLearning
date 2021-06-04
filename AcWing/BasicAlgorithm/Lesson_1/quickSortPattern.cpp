#include <iostream>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1e5+10;
ll q[maxn];

inline void quickSort(ll q[], ll l, ll r) {
    if (l>=r) return;

    //双指针
    int x = q[(l+r)>>1], i = l-1, j = r+1;
    while(i < j) {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if (i<j) swap(q[i], q[j]);
    }

    quickSort(q, l, j), quickSort(q, j+1, r);

}

int main(void) {
    int n = 0; cin >> n;
    fp(i, 1, n) scanf("%lld", &q[i]);
    quickSort(q, 1, n);

    fp(i, 1, n) printf("%lld ", q[i]);

    _getch();
    return 0;
}