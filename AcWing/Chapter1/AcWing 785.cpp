#include <iostream>

using namespace std;

const int N = 1e5+10;
typedef long long ll;

int n;
ll q[N];

inline void quick_sort(ll *q, ll l, ll r) {
    if (l>=r) return ;
    
    ll x = q[l+r>>1], i = l-1, j = r+1;
    while (i<j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i<j) swap(q[i], q[j]);
    }
    
    quick_sort(q, l, j), quick_sort(q, j+1, r);
}

int main(void) {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%lld", &q[i]);
    
    quick_sort(q, 0, n-1);

    for (int i=0; i<n; i++) printf("%lld ", q[i]);
    
    return 0;
}