#include <iostream>

using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y) {    //AcWing 204. 表达整数的奇怪方式
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    LL d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

int main(void) {
    int n;
    scanf("%d", &n);

    bool flag = true;   //是否有解

    LL a1, m1;  //a1, m1存储最终合并所有式子后的系数
                //初始化为第一个式子的系数
    scanf("%lld%lld", &a1, &m1);

    //依次合并之后n-1个式子
    for (int i=0; i<n-1; i++) {
        LL a2, m2;
        scanf("%lld%lld", &a2, &m2);

        //求出k1, k2以及gcd(a1, a2)
        LL k1, k2;
        LL d = exgcd(a1, a2, k1, k2);
        //判定是否有解
        if ((m2-m1) % d) {
            flag = false;
            break;
        }

        k1 *= (m2-m1)/d;    //k1扩大(m2-m1)/gcd(a1, a2)倍
        LL t = a2/d;        //记录a2/gcd(a1, a2)项
        k1 = (k1%t+t)%t;    //最小化k1的值

        m1 = a1*k1+m1;      //更新系数m1
        a1 = abs(a1/d*a2);  //更新系数a1
    }

    if (flag) cout << (m1%a1+a1)%a1 << endl;    //取模保证最小正整数
    else puts("-1");

    return 0;
}