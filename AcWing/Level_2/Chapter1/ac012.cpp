#include <iostream>

using namespace std;    //12. 背包问题求具体方案

const int N = 1010;

int n, m;
int v[N], w[N];     //存储第i个物品的重量和价值
int f[N][N];    //不降维

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];  //从1开始，输入每个物品的重量和价值
    
    for (int i = n; i >= 1; i --)   //从最后一个物品开始往前推，便于求具体方案
        for (int j = 0; j <= m; j ++) {
            f[i][j] = f[i + 1][j];  //上一个状态
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);   //状态转移方程
        }
    
    //f[1][m]为01背包问题答案
    int j = m;  //初始体积为m
    for (int i = 1; i <= n; i ++)   //从前往后看每一个物品选或不选，利用贪心保证字典序最小
        if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i])  { //第i个物品可以选，那么由于字典序最小，则一定选   
            cout << i << " ";
            j -= v[i];  //更新剩余体积
        }
    
    return 0;
}