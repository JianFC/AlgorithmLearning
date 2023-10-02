#include <iostream>
#include <cstring>

using namespace std;     //AcWing 847. 图中点的层次

const int N = 100010, M = N;

int n, m;
int h[N], e[M], ne[M], idx;
int d[N];   //每个点到1号点的距离
int q[M], hh, tt = -1;

void add(int a, int b){    
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int bfs() {
    memset(d, -1, sizeof d);

    d[1] = 0;
    q[++tt] = 1;

    while (hh <= tt) {
        int t = q[hh++];

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] == -1) {
                d[j] = d[t] + 1;
                q[++ tt] = j;
            }
        }
    }

    return d[n];
}

int main(void) {
    scanf("%d%d", &n, &m);

    //注意初始化的位置
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    cout << bfs();

    return 0;
}