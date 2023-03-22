#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1000010;

int n;
int phi[N];     //phi[i]表示i的欧拉函数值
int primes[N], cnt;
bool st[N];

LL get_eulers(int n) {      //AcWing 874. 筛法求欧拉函数
    phi[1] = 1;

    for (int i=2; i<=n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            phi[i] = i-1;   //当i时质数时，有定义知1~i-1与i互质，故phi[i] = i-1;
        }

        for (int j=0; primes[j]<=n/i; j++) {
            st[primes[j]*i] = true;

            if (i%primes[j] == 0) {
                // 当i%primes[j] == 0时，primes[j]是i质因子，有函数定义可得如下公式
                phi[primes[j]*i] = primes[j]*phi[i];
                break;
            }

            // 当i%primes[j] != 0时，primes[j]不是i质因子，有函数定义可得如下公式
            phi[primes[j]*i] = phi[i]*(primes[j]-1);
        }
    }

    LL res = 0;
    for (int i=1; i<=n; i++) res += phi[i];
    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);

    cout << get_eulers(n) << endl;

    return 0;
}