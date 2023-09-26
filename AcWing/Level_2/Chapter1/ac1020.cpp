#include <iostream>
#include <cstring>

using namespace std;

const int N = 25, M = 90;

int n, m, K;
int f[N][M];    //f[i, j, k]表示从前i个气缸中选，氧气至少是j，氮气至少是k的所有选法重量最小值

int main() {
    cin >> n >> m >> K;
    
    memset(f, 0x3f, sizeof f);  //初始化f[0, 0]外的所有状态为正无穷
    f[0][0] = 0;
    
    while (K --) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        for (int i = n; i >= 0; i --)   //注意循环到0，可以为负数，小于0时取0
            for (int j = m; j >= 0; j --)
                f[i][j] = min(f[i][j], f[max(0, i - v1)][max(0, j - v2)] + w);  //小于0时取0   
    }
    
    cout << f[n][m] << endl;    //输出结果
    
    return 0;
}