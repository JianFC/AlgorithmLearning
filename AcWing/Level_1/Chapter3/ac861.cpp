#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];   //match[i]表示当前右半部中的点i匹配的左半部点
bool st[N];     //st[i]表示右半部点i是否已被某个特定的左半部点考虑过

void add(int a, int b) {    //AcWing 861. 二分图的最大匹配
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x) {
    for (int i=h[x]; i!=-1; i=ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;

            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

int main(void) {
    scanf("%d%d%d", &n1, &n2, &m);

    memset(h, -1, sizeof h);

    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);  //只需存储从左向右的边
    }

    int res = 0;
    for (int i=1; i<=n1; i++) {
        memset(st, false, sizeof st);
        if (find(i)) res++;
    }

    cout << res;

    return 0;
}