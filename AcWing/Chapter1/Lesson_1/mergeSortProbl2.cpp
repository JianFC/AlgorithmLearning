#include <iostream>
#include <conio.h>
typedef long long ll;

using namespace std;
const int maxn = 1e5+10;
ll q[maxn] = {0}, tmp[maxn] = {0};

inline ll merge_sort(ll *q, ll l, ll r) {
    if (l>=r) return 0;
    
    ll mid = (l+r)>>1;
    ll ans = merge_sort(q, l, mid) + merge_sort(q, mid+1, r);

    //归并过程
    int k=1, i = l, j = mid+1;
    while (i<=mid && j<=r) {
        if (q[i]<=q[j]) tmp[k++] = q[i++];
        else {
            ans += mid-i+1;     //注意公式推导
            tmp[k++] = q[j++];
        }
    } 

    //收尾过程
    while (i<=mid) tmp[k++] = q[i++];
    while (j<=r) tmp[k++] = q[j++];

    for (i=l, j=1; i<=r; i++, j++) q[i] = tmp[j];
    return ans;
}


int main(void) {
    int n = 0; scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%lld", &q[i]);
    printf("%lld", merge_sort(q, 1, n));

    _getch();
    return 0;
}