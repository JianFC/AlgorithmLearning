#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N], g[N];

int main() {    //AcWing 1014. 登山
    scanf("%d", &n);

    for (int i=1; i<=n; i++) scanf("%d", &a[i]);

    //预处理正向LIS
    for (int i=1; i<=n; i++) {
        f[i] = 1;
        for (int j=1; j<i; j++)
            if (a[i] > a[j])
                f[i] = max(f[i], f[j]+1);
    }

    //预处理反向LIS
    for (int i=n; i>=1; i--) {
        g[i] = 1;
        for (int j=n; j>i; j--)
            if (a[i] > a[j])
                g[i] = max(g[i], g[j]+1);
    }

    int res = 0;
    for (int k=1; k<=n; k++) res = max(res, f[k]+g[k]-1);

    printf("%d\n", res);

    return 0;
}