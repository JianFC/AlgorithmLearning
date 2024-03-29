#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;        //AcWing 850. Dijkstra求最短路 II

typedef pair<int, int> PII;

const int N = 200010, M = N;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c){      
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size()) {
        auto t = heap.top(); heap.pop();

        int ver = t.second, d = t.first;

        //判断最短距离是否已确定
        if (st[ver]) continue;
        st[ver] = true;

        //更新所有ver的出边的距离
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > d + w[i]) {
                dist[j] = d + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(void) {
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    cout << dijkstra();

    return 0;
}
