//并查集应用
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1010;
int fa[maxn], Rank[maxn];
int n, h;
ll r;
ll X[maxn], Y[maxn], Z[maxn];

inline void init(int n) {
    fp(i, 1, n) {
        fa[i] = i;
        Rank[i] = i;
    }
}

inline int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

inline void merge(int i, int j) {
    int x = find(i); int y = find(j);
    if (Rank[x] <= Rank[y]) 
        fa[x] = y;
    else 
        fa[y] = x;
    if (Rank[x] == Rank[y] && x!=y) Rank[y]++;
}

//检查两个球体是否相交或者相切，若相交或者相切，则合到一个集合里
inline bool check(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2) <= 4*r*r;
}

int main(void) {
    int t; cin >> t;
    while(t--) {
        memset(X, 0 ,sizeof(X));
        memset(Y, 0, sizeof(Y));
        memset(Z, 0, sizeof(Z));
        cin >> n >> h >> r;
        init(n);    //初始化并查集
        fp(i, 1, n) cin >> X[i] >> Y[i] >> Z[i];
        fa[1001] = 1001;    //用1001号结点代表奶酪底部
        fa[1002] = 1002;    //用1002号结点代表奶酪顶部
        fp(i, 1, n) {
            if (Z[i]<=r) merge(i, 1001);
            if (Z[i]+r>=h) merge(i, 1002);
        }
        //遍历所有结点，将所有相邻的球体合并
        fp(i, 1, n) {
            fp(j, 1, n) {
                if (check(X[i], Y[i], Z[i], X[j], Y[j], Z[j])) {
                    merge(i, j);
                }
            }
        }
        printf("%s\n", find(1001) == find(1002) ? "Yes" : "No");
    }

    _getch();
    return 0;
}