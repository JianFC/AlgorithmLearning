#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1057. 股票买卖 IV

const int N = 100010, M = 110;

int n, m;
int w[N], f[N][M][2];   //w[i]表示第i天的价格, f[i][j][0]表示前i天，进行了j次交易，手中无货的最大价值
                        //f[i][j][1]表示前i天，正在进行第j次交易，手中有货的方案的最大价值
                        
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);   //从1开始
    
    memset(f, -0x3f, sizeof f);     //初始化f数组
    for (int i = 0; i <= n; i ++) f[i][0][0] = 0;   //一次交易都不进行，初始化为0
    
    for (int i = 1; i <= n; i ++)   //枚举天数
        for (int j = 1; j <= m; j ++) {     //枚举交易数量
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);    //手中无货的转移方式
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]);    //手中有货的转移方式
        }
        
    int res = 0;    //=0保证收益>0，即一次都不交易
    for (int i = 0; i <= m; i ++) res = max(res, f[n][i][0]);   //最后一维为0，确保处于手中无货的状态
    
    cout << res << endl;
    
    return 0;
}