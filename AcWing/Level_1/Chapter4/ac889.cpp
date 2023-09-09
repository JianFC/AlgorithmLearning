#include <iostream>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

//快速幂
LL qmi(int a, int k, int p) {   //AcWing 889. 满足条件的01序列
    LL res = 1 % p;

    while (k) {
        if (k & 1) res = res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }

    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int a = 2 * n, b = n;
    int res = 1;

    //计算C(2n, n)
    for (int i = 1, j = a; i <= b; i++, j--) {
        res = (LL)res * j % mod;
        res = (LL)res * qmi(i, mod - 2, mod) % mod;
    }

    //计算(1/(n+1))*C(2n, n) （卡特兰数）
    res = (LL)res * qmi(n + 1, mod - 2, mod) % mod;

    cout << res;

    return 0;
}