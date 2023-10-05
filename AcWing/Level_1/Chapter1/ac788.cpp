#include <iostream>

using namespace std;         //AcWing 788. 逆序对的数量

typedef long long LL;

const int N = 1e5 + 10;

int q[N], tmp[N];

inline LL merge_sort(int *q, int l, int r) {      
    if (l >= r) return 0;

    int mid = (l + r) >> 1;
    LL ans = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

    int k = 1, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k ++] = q[i ++];
        else {
            ans += mid - i + 1;
            tmp[k ++] = q[j ++];
        }
    }

    while (i <= mid) tmp[k ++] = q[i ++];
    while (j <= r) tmp[k ++] = q[j ++];

    for (i = l, j = 1; i <= r; i ++, j ++) q[i] = tmp[j];
    
    return ans;
}

int main(void) {
    int n = 0; scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%lld", &q[i]);
    
    printf("%lld", merge_sort(q, 1, n));

    return 0;
}