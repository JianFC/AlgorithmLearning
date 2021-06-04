#include <iostream>
#include <conio.h>
typedef long long ll;

using namespace std;
const int maxn = 1e5+10;
ll q[maxn] = {0}, temp[maxn] = {0};

inline void merge_sort(ll *q, ll l, ll r) {
    //递归终点
    if (l>=r) return;
    
    //划分区间
    ll mid = (l+r)>>1;
    merge_sort(q, l, mid);
    merge_sort(q, mid+1, r);
    
    //合并区间
    ll k = 1, i = l, j = mid + 1;
    while(i<=mid && j<=r) {
        if (q[i] <= q[j]) temp[k++] = q[i++];
        else temp[k++] = q[j++];
    }
    
    while(i<=mid) temp[k++] = q[i++];
    while(j<=r) temp[k++] = q[j++];
    
    //更新原数组
    for (i=l, j=1; i<=r; i++, j++) q[i] = temp[j];
}


int main(void) {
    int n = 0; scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%lld", &q[i]);
    merge_sort(q, 1, n);
    for (int i=1; i<=n; i++) printf("%lld ", q[i]);

    _getch();
    return 0;
}