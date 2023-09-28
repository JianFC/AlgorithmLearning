#include <iostream>

using namespace std;

const int N = 1e5+10;

int n, m;
int a[N], s[N];

int main(void) {    //AcWing 795. 前缀和
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];    //前缀和初始化

    while (m --) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}