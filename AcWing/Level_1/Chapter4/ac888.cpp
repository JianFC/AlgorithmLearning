#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 5010;

int primes[N], cnt;
bool st[N];
int sum[N];

//线性筛
void get_primes(int n) {        //AcWing 888. 求组合数 IV
    for (int i = 2; i <= n; i++) {
        if (!st[i]) 
            primes[cnt++] = i;

        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

//求出n!中某个质因数p的个数
int get(int n, int p) {
    int res = 0;
    //计算公式 a!中包含p的个数 = a/p + a/p^2 + … + a/p^n (当a/p^n==0截止)
    //第一次循环 res += n/p
    //第二次循环 res += n/p^2
    //...
    while (n) {
        res += n / p;
        n /= p;
    }

    return res;
}

//高精度乘法
vector<int> mul(vector<int> &A, int b) {
    vector<int> C;

    for (int i = 0, t = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}


int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);

    get_primes(a);

    //对小于a的每一个质数，处理出其指数
    for (int i = 0; i < cnt; i++) {
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
    }

    //保存结果
    vector<int> res;
    res.push_back(1);

    //将所有质数相乘
    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < sum[i]; j++)
            res = mul(res, primes[i]);

    for (int i = res.size() - 1; i >= 0; i--) printf("%d", res[i]);
    puts("");

    return 0;
}