#include <iostream>

using namespace std;

const int N = 1000010;

int n, k;
int a[N];
int q[N], hh, tt = -1;

int main(void) {    //AcWing 154. 滑动窗口
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;

        if (i - k + 1 >= 0) printf("%d ", a[q[hh]]);
    }

    puts("");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;

        if (i - k + 1 >= 0) printf("%d ", a[q[hh]]);
    }

    return 0;
}