#include <iostream>
#include <cstring>

using namespace std;        //AcWing 848. 有向图的拓扑序列

const int N = 100010, M = 100010;

int n, m;
int h[N], e[M], ne[M], idx;
int q[N], hh, tt = -1;
int d[N];   //d[i]表示第i个结点的入度

void add(int a, int b) {    
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool toposort() {
    //将所有入度为0的点入队
    for (int i = 1; i <= n; i ++)
        if (!d[i]) q[++ tt] = i;

    while (hh <= tt) {
        int t = q[hh ++];

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j] --;
            if (d[j] == 0) q[++ tt] = j;
        }
    }

    return tt == n - 1;
}

int main(void) {
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b] ++;
    }

    if (toposort())
        for (int i = 0; i < n; i ++) printf("%d ", q[i]);
    else puts("-1");

    return 0;
}