#include <iostream>

using namespace std;    //278. 数字组合

const int N = 10010;

int n, m;
int f[N];   //f[i, j]表示所有只从前i个物品中选，且总体积恰好是j的所有选法的集合

int main() {
    cin >> n >> m;
    f[0] = 1;   //初始化f[0, 0] = 1， f[0, i] = 0;
    
    for (int i = 0; i < n; i ++) {
        int v;
        cin >> v;
        for (int j = m; j >= v; j --)
            f[j] += f[j - v];   //状态转移方程
    }
    
    cout << f[m] << endl;
    
    return 0;
}