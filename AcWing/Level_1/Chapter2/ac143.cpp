#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 3000010;

int n;
int a[N];
int son[M][2], idx;

void insert(int x) {    //AcWing 143. 最大异或对
    int p = 0;
    for (int i=30; ~i; i--) {
        int s = x>>i&1;

        if (!son[p][s]) son[p][s] = ++idx;
        p = son[p][s];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i=30; ~i; i--) {
        int s = x>>i&1;

        if (son[p][!s]) {
            res += 1<<i;    //异或
            p = son[p][!s];
        }
        else p = son[p][s];
    }

    return res;
}

int main(void) {
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        insert(a[i]);
    }

    int res = 0;
    for (int i=0; i<n; i++) res = max(res, query(a[i]));

    printf("%d", res);

    return 0;
}