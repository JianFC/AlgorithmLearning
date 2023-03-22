#include <iostream>

using namespace std;

typedef long long LL;

int exgcd(int a, int b, int &x, int &y) {       //AcWing 878. 线性同余方程
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    int d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        int a, b, m;
        scanf("%d%d%d", &a, &b, &m);

        int x, y;
        int d = exgcd(a, m, x, y);

        if (b % d) puts("impossible");  //当gcd(a, m)不能整除b时，无解
        else printf("%lld\n", (LL)x*(b/d)%m);
    }

    return 0;
}