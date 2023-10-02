#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N], n, k;

int quick_sort(int *q, int l, int r, int k) {   //AcWing 786. 第k个数
    if (l >= r) return q[l];

    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    if (j - l + 1 >= k) return quick_sort(q, l, j, k);
    else return quick_sort(q, j + 1, r, k - (j - l + 1));
}

int main(void) {
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);

    cout << quick_sort(q, 0, n - 1, k);

    return 0;
}
