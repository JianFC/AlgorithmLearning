#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int mod = 1e9+7;

int main(void) {        //AcWing 871. 约数之和
    int n;
    scanf("%d", &n);

    unordered_map<int, int> primes;

    while (n--) {
        int x;
        scanf("%d", &x);

        for (int i=2; i<=x/i; i++) 
            while (x%i == 0) 
                x /= i, primes[i]++;

        if (x > 1) primes[x]++;
    }

    LL res = 1;
    for (auto prime: primes) {
        LL p = prime.first, a = prime.second;

        //快速计算p^1+p^2+...+p^ak
        int t = 1;
        while (a--)  t = (t*p+1)%mod;

        res = res*t%mod;
    }

    cout << res;

    return 0;
}