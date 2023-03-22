#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

struct Edge {
    int a, b, w;
} edges[M];

int n, m, k;
int dist[N];
int last[N];    //dist前一次迭代结果备份，防止在有边数限制时出现串联

int bellman_ford() {        //AcWing 853. 有边数限制的最短路
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i=0; i<k; i++) {
        //备份上一次迭代结果
        memcpy(last, dist, sizeof dist);

        for (int j=0; j<m; j++) {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], last[e.a] + e.w);
        }
    }

    //返回-1可能存在二义性。
    if (dist[n] > 0x3f3f3f3f/2) return 0x3f3f3f3f;
    return dist[n];
}

int main(void) {
    scanf("%d%d%d", &n, &m, &k);

    for (int i=0; i<m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    int t = bellman_ford();

    if (t == 0x3f3f3f3f) puts("impossible");
    else printf("%d\n", t);

    return 0;
}