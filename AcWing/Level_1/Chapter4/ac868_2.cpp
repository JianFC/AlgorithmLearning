#include <iostream>

using namespace std;        //868 筛质数

const int N = 1000010;

int n;
int primes[N], cnt;
bool st[N];

//埃氏筛法，时间复杂度O(nloglogn)，可视为O(n)
void get_primes(int n) {    //AcWing 868. 筛质数
    for (int i = 2; i <= n; i ++) {
        if (!st[i]) {
            primes[cnt ++] = i;

            for (int j = i + i; j <= n; j += i) 
                st[j] = true;
        }
    }
}

int main(void) {
    scanf("%d", &n);

    get_primes(n);

    printf("%d", cnt);

    return 0;
}
