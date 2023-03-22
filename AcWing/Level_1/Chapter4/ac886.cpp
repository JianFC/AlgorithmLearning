#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100010, mod = 1e9+7;

// fact[i]表示i! % mod, infact[i]表示(i!)^(-1) % mod
LL fact[N], infact[N]; 

LL qmi(int a, int k, int p) {       //AcWing 886. 求组合数 II
    LL res = 1 % p;

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

    //预处理fact（阶乘）与infact（阶乘的逆）的数组
    fact[0] = infact[0] = 1;
    for (int i=1; i<N; i++) {
        fact[i] = (LL)fact[i-1]*i%mod;
        infact[i] = (LL)infact[i-1]*qmi(i, mod-2, mod)%mod;
    }

    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%lld\n", fact[a]*infact[b]%mod * infact[a-b]%mod);    //组合数公式
    }

    return 0;
}