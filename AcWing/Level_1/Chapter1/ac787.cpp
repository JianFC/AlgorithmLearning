#include <iostream>
typedef long long ll;

using namespace std;
const int N = 1e5 + 10;
ll q[N] = {0}, temp[N] = {0};

inline void merge_sort(ll *q, ll l, ll r) {     //AcWing 787. 归并排序
    if (l >= r) return;

    ll mid = (l + r) >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    ll k = 1, i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if (q[i] <= q[j]) temp[k ++] = q[i ++];
        else temp[k++] = q[j ++];
    }

    while(i <= mid) temp[k ++] = q[i ++];
    while(j <= r) temp[k ++] = q[j ++];

    for (i = l, j = 1; i <= r; i ++, j ++) q[i] = temp[j];
}


int main(void) {
    int n = 0; scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%lld", &q[i]);
    merge_sort(q, 1, n);

    for (int i = 1; i <= n; i ++) printf("%lld ", q[i]);

    return 0;
}