#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;     //AcWing 859. Kruskal算法求最小生成树

const int N = 100010, M = 2 * N, INF = 0x3f3f3f3f;

struct Edge {       
    int a, b, w;

    bool operator< (const Edge &W) const {
        return w < W.w;
    }
} edges[M];

int n, m;
int p[N];

//并查集
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal() {
    //对所有边进行排序，算法瓶颈
    sort(edges, edges + m);   

    int res = 0, cnt = 0;   // res记录最小生成树权重，cnt记录当前最小生成树边数
    for (int i = 0; i < m; i ++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        if (find(a) != find(b)) {   
            res += w;
            cnt++;  
            p[find(a)] = find(b);   //将两个连通块合并   
        }
    }

    if (cnt < n - 1) return INF;
    return res;
}

int main(void) {
    scanf("%d%d", &n, &m);

    //初始化并查集
    for (int i = 1; i <= n; i ++) p[i] = i;

    for (int i = 0; i < m; i ++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    int t = kruskal();

    if (t == INF) puts("impossible");
    else printf("%d", t);

    return 0;
}