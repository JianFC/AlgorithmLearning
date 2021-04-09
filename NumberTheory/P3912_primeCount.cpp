// P3912 素数个数
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++) 
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1e8+10;
bool isPrime[maxn];
int Prime[80000000], cnt = 0;
int n;
ll sum = 0;

inline void getPrime(int n) {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for (int i=2; i<=n; i++) {
        if (isPrime[i]) {
            Prime[++cnt] = i;
            sum++;
        }
        
        for (int j=1; (j<=cnt)&&(i*Prime[j]<=n); j++) {
            isPrime[i*Prime[j]] = 0;
            if (i%Prime[j] == 0)
                break;
        }
    }
}

int main(void) {
    cin >> n;
    getPrime(n);
    cout << sum;

    _getch();
    return 0;
}