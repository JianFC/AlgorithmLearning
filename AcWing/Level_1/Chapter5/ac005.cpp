#include <iostream>

using namespace std;

// N ~ 1000 * log(2000) = 11000
const int N = 15000, M = 2010;

int n, m;
int v[N], w[N], cnt;    //cnt代表将每种物品分组后，转换为01背包问题里物品的总个数
int f[M];   //降维后01背包问题

int main(void) {    //AcWing 5. 多重背包问题 II优化
    scanf("%d%d", &n, &m);

    //通过二进制优化将多重背包转换为01背包问题
    for (int i = 1; i <= n; i++) {
        int a, b, s;    //a表示容量，b表示价值，s表示数量
        scanf("%d%d%d", &a, &b, &s);

        //将s[i]件物品划分为log(s[i])上取整组
        int k = 1;
        while (k <= s) {
            cnt ++;
            v[cnt] = k * a;
            w[cnt] = k * b;
            s -= k, k *= 2; //s减去k，k倍增
        }

        // 若s还有剩余，则补上C = S-(1+2+..+2^k) 
        if (s) {
            cnt++;
            v[cnt] = s * a;
            w[cnt] = s * b;
        }
    }

    //01背包问题求解
    for (int i = 1; i <= cnt; i ++)
        for (int j = m; j >= v[i]; j --) 
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}