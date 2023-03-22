#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], cnt;

void down(int u) {      //AcWing 838. 堆排序
    int t = u;
    if (2*u<=cnt && h[2*u]<h[t]) t = 2*u;
    if (2*u+1<=cnt && h[2*u+1]<h[t]) t = 2*u+1;
    if (t != u) {
        swap(h[t], h[u]);
        down(t);
    }
}

void up(int u) {
    while (u/2 && h[u/2]>h[u]) {
        swap(h[u/2], h[u]);
        u >>= 1;
    }
}

int main(void) {
    scanf("%d%d", &n, &m);

    for (int i=1; i<=n; i++) scanf("%d", &h[i]);
    cnt = n;

    for (int i=n/2; i; i--) down(i);

    while (m--) {
        printf("%d ", h[1]);
        h[1] = h[cnt], cnt--;
        down(1);
    }

    return 0;
}