#include <iostream>

using namespace std;

typedef long long LL;

LL qmi(int a, int k, int p) {       //AcWing 876. 快速幂求逆元
    LL res = 1%p;
    while (k) {
        if (k & 1) res = res*a%p;
        k >>= 1;
        a = (LL)a*a%p;
    }

    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        int a, p;
        scanf("%d%d", &a, &p);

        //特判，当a为p得倍数时，a，p不互质，不满足b * x = 1 (mod p)
        //直接输出impossible
        if (a%p == 0) puts("impossible");
        else printf("%lld\n", qmi(a, p-2, p));
    }

    return 0;
}
