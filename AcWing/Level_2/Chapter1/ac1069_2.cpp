#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;    //1069. 凸多边形的划分（高精度）

typedef long long LL;

const int N = 55, M = 35, INF = 1e9 + 10;   //M表示高精度的位数

int n;
int w[N];   //每个点的权值
LL f[N][N][M];    //区间DP状态数组，f[L][R]表示(L, L + 1), (L + 1, L + 2), ...
                //(R - 1, R), (R, L)多边形划分成三角形的方案的最小权值，最后一维高精度

void add(LL a[], LL b[]) {      //数组高精度加法
    static LL c[M];  //暂时存储答案
    memset(c, 0, sizeof c);     //初始化
    for (int i = 0, t = 0; i < M; i ++) {   //t存储进位
        t += a[i] + b[i];
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);     //将c数组结果copy到a中
}

void mul(LL a[], LL b) {    //数组高精度乘
    static LL c[M];
    memset(c, 0, sizeof c);
    LL t = 0;   //注意t的类型为long long，不能定义到循环初始化中，否则溢出
    for (int i = 0; i < M; i ++) {   //M = 35,不用考虑t
        t += a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}

int cmp(LL a[], LL b[]) {   //高精度比较
    for (int i = M - 1; i >= 0; i --)
        if (a[i] > b[i]) return 1;  
        else if (a[i] < b[i]) return -1;
    return 0;   //两数相等
}

void printf(LL a[]) {   //高精度输出函数
    int k = M - 1;  //从最高位开始
    while (k && !a[k]) k --;    //去除前导0
    while (k >= 0) cout << a[k --];
    cout << endl;
}
                
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> w[i];
    
    LL tmp[M];     //暂存高精度运算结果
    for (int len = 3; len <= n; len ++)     //len从3开始枚举，枚举长度
        for (int l = 1; l + len - 1 <= n; l ++) {   //枚举左端点
            int r = l + len - 1;
            
            f[l][r][M - 1] =  1;  //初始化f[l][r]为10^34，即正无穷
            for (int k = l + 1; k < r; k ++) {    //枚举分界点
                memset(tmp, 0, sizeof tmp);     //初始化
                tmp[0] = w[l];  //trick，将第一个乘数赋值
                mul(tmp, w[k]);
                mul(tmp, w[r]);
                add(tmp, f[k][r]);
                add(tmp, f[l][k]);
                
                if (cmp(f[l][r], tmp) > 0)
                    memcpy(f[l][r], tmp, sizeof tmp);
            }
        }
        
    printf(f[1][n]);
    
    return 0;
}