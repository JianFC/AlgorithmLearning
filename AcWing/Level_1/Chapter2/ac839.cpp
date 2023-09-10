#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

//ph[k]：第k个插入的数在堆中的下标
//hp[i]：下标是i的点是第几个插入的数
int h[N], ph[N], hp[N], cnt;

void heap_swap(int a, int b) {      //AcWing 839. 模拟堆
    swap(ph[hp[a]], ph[hp[b]]);     //交换ph指针
    swap(hp[a], hp[b]);         //交换hp指针
    swap(h[a], h[b]);           //交换值
}

void down(int u) {
    int t = u;
    if (2 * u <= cnt && h[2 * u] < h[t]) t = 2 * u;
    if (2 * u + 1 <= cnt && h[2 * u + 1] < h[t]) t = 2 * u + 1;
    if (t != u) {
        heap_swap(t, u);
        down(t);
    }
}

void up(int u) {
    while (u / 2 && h[u / 2] > h[u]) {
        heap_swap(u / 2, u);
        u >>= 1;
    }
}

int main(void) {
    int n, m = 0;
    scanf("%d", &n);

    while (n -- ) {
        int k, x;
        char op[10];
        scanf("%s", op);

        if (!strcmp(op, "I")) {
            scanf("%d", &x);
            cnt++, m++;
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }
        else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
        else if (!strcmp(op, "DM")) {
            heap_swap(1, cnt);
            cnt--;
            down(1);
        }
        else if (!strcmp(op, "D")) {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, cnt);
            cnt--;
            down(k), up(k);
        }
        else {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }

    return 0;
}