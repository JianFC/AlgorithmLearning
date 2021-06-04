#include <iostream>
typedef long long ll;

using namespace std;
const int maxn = 1e5+10;
ll q[maxn] = {0};

inline void quick_sort(ll *q, ll l, ll r) {
    if (l>=r) return;   

    int x = q[l+r>>1], i = l-1, j = r+1;
    while(i<j) {
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);
        if(i<j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j), quick_sort(q, j+1, r);
}

int main(void) {
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    for (int i=1; i<=n; i++) scanf("%lld", &q[i]);
    quick_sort(q, 1, n);

    printf("%lld", q[k]);

    return 0;
}
