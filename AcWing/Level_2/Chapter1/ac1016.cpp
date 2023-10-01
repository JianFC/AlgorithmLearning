#include <iostream>
#include <algorithm>

using namespace std;    //AcWing 1016. 最大上升子序列和

const int N = 1010;

int n;
int a[N];
int f[N];

int main() {    
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

    int res = 0;
    for (int i = 1; i <= n; i ++) {
        f[i] = a[i];
        for (int j = 1; j < i; j ++)
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + a[i]);    //注意是a[i]

        res = max(res, f[i]);
    }

    printf("%d", res);

    return 0;
}