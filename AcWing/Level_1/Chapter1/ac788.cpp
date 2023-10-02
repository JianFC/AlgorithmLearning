#include <iostream>
//#include <conio.h>
typedef long long ll;

using namespace std;
const int N = 1e5 + 10;
ll q[N] = {0}, tmp[N] = {0};

inline ll merge_sort(ll *q, ll l, ll r) {       //AcWing 788. 逆序对的数量
    if (l >= r) return 0;

    ll mid = (l + r) >> 1;
    ll ans = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

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

    //_getch();
    return 0;
}