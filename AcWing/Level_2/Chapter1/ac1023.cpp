#include <iostream>

using namespace std;    //1023. 买书

const int N = 1010;

int m;
int v[4] = {10, 20, 50, 100};
int f[N];   //f[i, j]表示从前i个物品中选，且总体积恰好是j的所有选法的数量

int main() {
    cin >> m;
    
    f[0] = 1;   //初始化f[0, 0] = 1
    for (int i = 0; i < 4; i ++) 
        for (int j = v[i]; j <= m; j ++)    //完全背包从小到大循环
            f[j] += f[j - v[i]];    //状态转移方程
    
    cout << f[m] << endl;
    
    return 0;
}