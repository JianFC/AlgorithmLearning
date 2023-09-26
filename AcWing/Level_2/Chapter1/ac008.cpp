#include <iostream>

using namespace std;

const int N = 110;

int n, V, M;
int f[N][N];    //f[i, j, k]表示所有从前i个物品中选，总体积不超过j，总重量不超过k的所有选法的价值最大值

int main() {
    cin >> n >> V >> M;
    
    for (int i = 0; i < n; i ++) {
        int v, m, w;
        cin >> v >> m >> w;
        for (int j = V; j >= v; j --)   //从大到小的遍历顺序
            for (int k = M; k >= m; k --)
                f[j][k] = max(f[j][k], f[j - v][k - m] + w);    //状态转移方程
    }
    
    cout << f[V][M] << endl;
    
    return 0;
}