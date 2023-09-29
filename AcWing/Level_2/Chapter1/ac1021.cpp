#include <iostream>

using namespace std;    //1021. 货币系统

typedef long long LL;

const int N = 3010;

int n, m;
LL f[N];   //完全背包问题求方案数

int main() {
    cin >> n >> m;
    
    f[0] = 1;   //初始化
    
    for (int i = 0; i < n; i ++) {
        int v;
        cin >> v;
        for (int j = v; j <= m; j ++) f[j] += f[j - v];     //状态转移方程
    }
    
    cout << f[m] << endl;
    
    return 0;
}