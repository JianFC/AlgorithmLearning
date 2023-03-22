#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210, INF = 0x3f3f3f3f;

int n, m, Q;
int d[N][N];

void floyd() {      //AcWing 854. Floyd求最短路
    for (int k=1; k<=n; k++)    //枚举阶段
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}

int main(void) {
    scanf("%d%d%d", &n, &m, &Q);

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n;j ++)
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

    for (int i=0; i<m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
    }

    floyd();

    while (Q--) {
        int x, y;
        scanf("%d%d", &x, &y);

        if (d[x][y] > INF/2) puts("impossible");
        else printf("%d\n", d[x][y]);
    }

    return 0;
}