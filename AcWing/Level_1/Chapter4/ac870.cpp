#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;      //AcWing 870. 约数个数

typedef long long LL;

const int mod = 1e9 + 7;

int main(void) {    
    int n;
    scanf("%d", &n);

    //哈希表
    unordered_map<int, int> primes;

    //质因数分解
    while (n--) {
        int x;
        scanf("%d", &x);

        for (int i = 2; i <= x / i; i ++) 
            while (x % i == 0) 
                x /= i, primes[i] ++;

        if (x > 1) primes[x] ++;
    }

    LL res = 1;
    for (auto p: primes) res = res * (p.second + 1) % mod;

    cout << res << endl;

    return 0;
}