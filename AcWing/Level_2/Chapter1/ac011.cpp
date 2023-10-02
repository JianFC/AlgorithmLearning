#include <iostream>
#include <cstring>

using namespace std;    //11. 背包问题求方案数

const int N = 1010, mod = 1e9 + 7;

int n, m;
int f[N], g[N];     //f[i, j]01背包定义，j表示恰好体积是j
                    //g[i, j]表示f[i, j]取到最大值的方案数，优化一维

int main() {
    cin >> n >> m;
    
    memset(f, -0x3f, sizeof f);     //定义更改，需要初始化
    f[0] = 0;
    g[0] = 1;   //初始化方案
    
    for (int i = 0; i < n; i ++) {
        int v, w;
        cin >> v >> w;
        
        for (int j = m; j >= v; j --) {  //优化维数后，从大到小循环
            int maxv = max(f[j], f[j - v] + w);
            int cnt = 0;    //暂时记录方案数
            if (maxv == f[j]) cnt += g[j];  
            if (maxv == f[j - v] + w) cnt += g[j - v];
            g[j] = cnt % mod;   //更新g[j]
            f[j] = maxv;    //更新f[j]
         }
    }
    
    int res = 0;
    for (int i = 0; i <= m; i ++) res = max(f[i], res);  //找出最大值，注意取等
    
    int cnt = 0;    //记录所有最大值的所有方案
    for (int i = 0; i <= m; i ++)
        if (f[i] == res) cnt = (cnt + g[i]) % mod;  //防止溢出
    
    cout << cnt << endl;
    
    return 0;
}