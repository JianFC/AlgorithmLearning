// P3383 【模板】线性筛素数
// References: https://www.luogu.com.cn/problem/solution/P3383

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
bool isPrime[maxn]; //isPrime[i]=1表示i为素数，否则为合数
int Prime[5000000] = {0}, cnt=0;   //Prime[i]表示在[1, n]范围中的第i个素数, cnt用于Prime计数
int n, q;

//线性筛素数，时间复杂度为O(n)，求出所有在范围[1, n]之内的素数，且筛出的素数按从小到大排序。
inline void getPrime(int n) {
    memset(isPrime, 1, sizeof(isPrime));    //isPrime是布尔数组，每个元素刚好一个字节，所以相当于将所有元素置1
    isPrime[1] = 0;     //1不是素数
    //从2到n筛素数
    for (int i=2; i<=n; i++) {
        if (isPrime[i])     //i未被后面的循环筛掉
            Prime[++cnt] = i;

        for (int j=1; (j<=cnt)&&(i*Prime[j]<=n)/*不超范围*/; j++) {
            isPrime[i*Prime[j]] = 0;    //筛掉i*Prime[j]
            if (i%Prime[j] == 0) {
                break;  //保证Prime[j]是合数(i*Prime[j])的最小质因数。证明过程可使用反证法
            }
        }
    }
}


int main(void) {
    cin >> n >> q;
    getPrime(n);
    int index;
    fp(i, 1, q) {
        cin >> index;
        cout << Prime[index] << endl;
    }

    _getch();
    return 0;
}
