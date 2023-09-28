#include <iostream>

using namespace std;    //1019. 庆功会

const int N = 6010;

int n, m;
int f[N];   //f[i, j]表示只考虑前i个物品，且总体积不超过j的所有选法的最大值

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i ++) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = m; j >= 0; j --)   //降维后从大到小枚举体积
            for (int k = 0; k <= s && k * v <= j; k ++)     //枚举决策
                f[j] = max(f[j], f[j - k * v] + k * w);     //状态转移方程
    }
    
    cout << f[m] << endl;
    
    return 0;
}