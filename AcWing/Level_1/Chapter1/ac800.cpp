#include <iostream>

using namespace std;

const int N = 1e5+10;

int n, m, x;
int a[N], b[N];

int main(void) {    //AcWing 800. 数组元素的目标和
    scanf("%d%d%d", &n, &m, &x);

    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int j=0; j<m; j++) scanf("%d", &b[j]);

    for (int i=0, j=m-1; i<n; i++) {
        while (j>=0 && a[i]+b[j]>x) j--;
        if (j>=0 && a[i]+b[j]==x) cout << i << " " << j;
    }

    return 0;
}