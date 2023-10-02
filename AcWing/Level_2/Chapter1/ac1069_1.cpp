#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;    //1069. 凸多边形的划分（朴素版）

const int N = 55, M = 35, INF = 1e9 + 10;   //M表示高精度的位数

int n;
int w[N];   //每个点的权值
int f[N][N];    //区间DP状态数组，f[L][R]表示(L, L + 1), (L + 1, L + 2), ...
                //(R - 1, R), (R, L)多边形划分成三角形的方案的最小权值
                
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> w[i];
    
    for (int len = 3; len <= n; len ++)     //len从3开始枚举，枚举长度
        for (int l = 1; l + len - 1 <= n; l ++) {   //枚举左端点
            int r = l + len - 1;
            f[l][r] = INF;  //初始化f[l][r]
            for (int k = l + 1; k < r; k ++)    //枚举分界点
                f[l][r] = min(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r]); //状态转移方程
        }
        
    cout << f[1][n] << endl;    //答案
    
    return 0;
}