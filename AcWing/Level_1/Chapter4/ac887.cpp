#include <iostream>

using namespace std;

typedef long long LL;

//快速幂用于求逆元
LL qmi(int a, int k, int p) {       //AcWing 887. 求组合数 III
    LL res = 1 % p;

    while (k) {
        if (k & 1) res = res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }

    return res;
}

//求C(a, b, p)
int C(int a, int b, int p) {
    if (b > a) return 0;

    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--) {
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p - 2, p) % p;
    }

    return res;
}

//lucas定理
int lucas(LL a, LL b, int p) {
    if (a < p && b < p) return C(a, b, p);
    // C(a, b) = C(a mod p, b mod p) * C(a / p, b / p) (mod p)
    return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p; 
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        LL a, b;
        int p;
        scanf("%lld%lld%d", &a, &b, &p);

        printf("%d\n", lucas(a, b, p));
    }

    return 0;
}