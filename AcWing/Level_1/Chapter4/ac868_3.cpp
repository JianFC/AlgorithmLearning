#include <iostream>

using namespace std;

const int N = 1000010;

int n;
int primes[N], cnt;
bool st[N];

//线性筛法，时间复杂度O(n)
void get_primes(int n) {        ////AcWing 868. 筛质数
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;

        //从小到大枚举所有质数
        //且primes[j]的最大值为min(n/i, i);
        //当i比n/i小时，i控制循环次数（循环i次时所有比i的质数都已存入primes数组）
        //故循环次数不会超过cnt的范围
        //当i比n/i大时，n/i控制循环次数。primes[j]仍比i小，不会越界
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;

            if (i % primes[j] == 0) break;
        }
    }
}

int main(void) {
    scanf("%d", &n);

    get_primes(n);

    printf("%d", cnt);

    return 0;
}
