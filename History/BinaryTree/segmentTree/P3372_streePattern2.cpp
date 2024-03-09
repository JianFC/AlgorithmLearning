#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1e5+10;
ll arr[maxn] = {0}, stree[maxn<<2] = {0}, tag[maxn<<2] = {0};

inline ll ls(ll p) { return p<<1;}
inline ll rs(ll p) { return p<<1|1;}

inline void pushUp(ll p) {
    stree[p] = stree[ls(p)] + stree[rs(p)];
    // stree[p] = min(stree[ls(p)], stree[rs(p)]);
    // stree[p] = max(stree[ls(p)], stree[rs(p)]);
}

//线段树建树
void build(ll p, ll l, ll r) {
    if (l == r) {
        stree[p] = arr[l]; return ;
    }
    ll mid = (l+r)>>1;
    build(ls(p), l, mid);
    build(rs(p), mid+1, r);
    pushUp(p);
}

//线段树区间修改
//下放懒标记
inline void f(ll p, ll l, ll r, ll k) {
    tag[p] += k;
    stree[p] += k*(r-l+1);
}

inline void pushDown(ll p, ll l, ll r) {
    ll mid = (l+r)>>1;
    f(ls(p), l, mid, tag[p]);
    f(rs(p), mid+1, r, tag[p]);
    tag[p] = 0;     //下放完成，懒标记清零
}

inline void update(ll ul, ll ur, ll p, ll l, ll r, ll k) {
    if (ul <= l && r <= ur) {
        tag[p] += k;        //更新懒标记
        stree[p] += k*(r-l+1);
        return ;      
    }
    pushDown(p, l, r);  //下放懒标记
    ll mid = (l+r)>>1;
    if (ul <= mid) update(ul, ur, ls(p), l, mid, k);
    if (ur > mid) update(ul, ur, rs(p), mid+1, r, k);
    pushUp(p);
}

//线段树区间查询
inline ll query(ll ql, ll qr, ll p, ll l, ll r) {
    if (ql <= l && r <= qr) {
        return stree[p];
    }
    pushDown(p, l, r);  //下放懒标记
    ll ans = 0, mid = (l+r)>>1;
    if (ql <= mid) ans += query(ql, qr, ls(p), l, mid);     // ans = query(ql, qr, ls(p), l, mid)
    if (qr > mid) ans += query(ql, qr, rs(p), mid+1, r);
    return ans;
}

int main(void) {
    ll n, m, op, x, y, k;
    cin >> n >> m;
    fp(i, 1, n) scanf("%lld", &arr[i]);
    build(1, 1, n);
    fp(i, 1, m) {
        scanf("%lld %lld %lld", &op, &x, &y);
        switch(op) {
        case 1:
            scanf("%lld", &k);
            update(x, y, 1, 1, n, k);
            break;
        case 2:
            printf("%lld\n", query(x, y, 1, 1, n));
            break;
        }
    }

    _getch();
    return 0;
}
