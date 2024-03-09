//并查集简单应用
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
const int maxn = 5e3+5;
int fa[maxn], Rank[maxn];
int m, n, p;
int mi, mj;
int pi, pj;

inline void init(int n) {
    fp(i, 1, n) {
        fa[i] = i;
        Rank[i] = 1;
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

int main(void) {
    cin >> n >> m >> p;
    init(n);    //初始化并查集
    fp(i, 1, m) {
        cin >> mi >> mj;
        merge(mi, mj);
    }

    fp(i, 1, p) {
        cin >> pi >> pj;
        printf("%s\n", find(pi) == find(pj) ? "Yes" : "No");   
    }

    _getch();
    return 0;
}