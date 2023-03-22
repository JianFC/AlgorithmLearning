#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];    //朴素版Dijkstra算法使用临界矩阵
int dist[N];    //dist[i]表示第i个结点到1号点的最短距离
bool st[N];     //st[i]表示第i个结点是否已确定最短距离

int dijkstra() {    //AcWing 849. Dijkstra求最短路 I
    //初始化dist数组
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i=0; i<n; i++) {
        int t = -1;

        for (int j=1; j<=n; j++)
            if (!st[j] && (t==-1 || dist[j]<dist[t]))
                t = j;

        st[t] = true;

        // 用t更新其他点到起点的距离
        for (int j=1; j<=n; j++)
            dist[j] = min(dist[j], dist[t]+g[t][j]);
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(void) {
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    for (int i=0; i<m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }

    cout << dijkstra();

    return 0;
}