#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;        //AcWing 858. Prim算法求最小生成树

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];    //dist[i]表示当前结点i到连通块的最短距离
bool st[N];

int prim() {        
    memset(dist, 0x3f, sizeof dist);

    int res = 0;    //记录最小生成树权重
    for (int i = 0; i < n; i ++) {  //迭代n次
        int t = -1;

        //找出距离集合最近的点
        for (int j = 1; j <= n; j ++) 
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;

        //第一个点特判
        if (i && dist[t] == INF) return INF;
        if (i) res += dist[t];
        st[t] = true;   //加入连通块

        //用t更新其他邻边到集合的距离
        for (int j = 1; j <= n; j ++) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

int main(void) {
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    for (int i = 0; i < m; i ++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == INF) puts("impossible");
    else printf("%d\n", t);

    return 0;
}
