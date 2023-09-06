#include <iostream>

using namespace std;

typedef long long LL;

const int N = 20;

int n, m;
int p[N];

int main(void) {        //AcWing 890. 能被整除的数
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) scanf("%d", &p[i]);

    int res = 0;    //存储容斥原理计算结果
    //位运算优化，将i视为m位二进制数，一共需要循环2^m-1次，即计算2^m-1项
    //每一次循环，i都存储了不同的选择方案
    for (int i = 1; i < 1 << m; i++) {
        int t = 1, s = 0;   //t存储当前被选中的质数乘积，s存储当前被选中的共有多少个Spi
        //计算t和s,
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                s++;    //p[j]质数被选中

                if ((LL)t * p[j] > n) {  //当前质数乘积已超过n的范围，1~n中不存在该项的倍数
                    t = -1;
                    break;
                }

                //更新t
                t *= p[j];
            } 
        }

        if (t != -1) {
            if (s % 2) res += n / t;  //当前项中含有奇数个Sp
            else res -= n / t;        //当前项中含有偶数个Sp
        }
    }

    cout << res << endl;

    return 0;
}