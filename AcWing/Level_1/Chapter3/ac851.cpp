#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = N;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
int q[M], hh, tt = -1;
bool st[N];     //st[i]表示第i个结点是否在队列中，即是否为待更新的点

void add(int a, int b, int c) {     //AcWing 851. spfa求最短路
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    //起点入队
    q[++tt] = 1;
    st[1] = true;

    while (hh <= tt) {
        int t = q[hh++];
        st[t] = false;  //已出队

        //更新t的所有出边
        for (int i=h[t]; i!=-1; i=ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t]+w[i]) {
                dist[j] = dist[t]+w[i];

                if (!st[j]) {
                    q[++tt] = j;
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return 0x3f3f3f3f;
    return dist[n];
}

int main(void) {
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    for (int i=0; i<m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    int t = spfa();

    if (t == 0x3f3f3f3f) puts("impossible");
    else printf("%d", t);

    return 0;
}
