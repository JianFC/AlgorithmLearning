#include <iostream>

using namespace std;

typedef long long LL;

// 返回 a^k mod p
LL qmi(int a, int k, int p) {       //AcWing 875. 快速幂
    LL res = 1 % p;
    while (k) {
        //初始时a = a^(2^0) 
        if (k & 1) res = res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }

    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        int a, k, p;
        scanf("%d%d%d", &a, &k, &p);
        printf("%lld\n", qmi(a, k, p));
    }

    return 0;
}