#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N], cnt[N];

int find(int x) {       //AcWing 837. 连通块中点的数量
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(void) {
    scanf("%d%d", &n, &m);

    for (int i=1; i<=n; i++) p[i] = i, cnt[i] = 1;

    while (m--) {
        int a, b;
        char op[3];
        scanf("%s", op);

        if (op[0] == 'C') {
            scanf("%d%d", &a, &b);
            a = find(a), b = find(b);
            p[a] = b;
            if (a != b) cnt[b] += cnt[a];
        }
        else if (op[1] == '1') {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else {
            scanf("%d", &a);
            printf("%d\n", cnt[find(a)]);
        }
    }

    return 0;
}