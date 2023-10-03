#include <iostream>

using namespace std;     //AcWing 240. 食物链

const int N = 50010;

int n, m;
int p[N], d[N];

//维护每个结点到根结点的距离信息
int find(int x) {      

    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }

    return p[x];
}

int main(void) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) p[i] = i;

    int res = 0;
    while (m --) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);

        if (x > n || y > n) res ++;
        else {
            if (t == 1) {
                int px = find(x), py = find(y);
                if (px == py && (d[x] - d[y]) % 3) res ++;
                else if (px != py) {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else if  (t == 2) {
                int px = find(x), py = find(y);
                if (px == py && (d[x] - d[y] - 1) % 3) res ++;
                else if (px != py) {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }

    printf("%d", res);

    return 0;
}
