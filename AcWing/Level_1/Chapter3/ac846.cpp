#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, M = 2*N;

int n;
int h[N], e[M], ne[M], idx;
bool st[N];
int ans = N;

void add(int a, int b) {    //AcWing 846. 树的重心
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

//返回以u为根的子树的结点个数
int dfs(int u) {
    st[u] = true;

    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int s = dfs(j);
            sum += s;
            res = max(res, s);
        }
    }

    res = max(res, n - sum);
    ans = min(ans, res);

    return sum;

}

int main(void) {
    scanf("%d", &n);

    memset(h, -1, sizeof h);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans;

    return 0;
}
