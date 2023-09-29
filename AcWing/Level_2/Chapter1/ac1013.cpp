#include <iostream>

using namespace std;    //1013. 机器分配

const int N = 15, M = 20;

int n, m;
int w[N][M];    //w[i][j]表示公司i分配j台机器的利润
int f[N][M];    //f[i][j]表示从前i组物品中选，总体积不超过j的所有选法的价值最大值
int way[N];     //way[i]表示第i个公司分配多少台机器

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++)   //枚举每组物品
        for (int j = 1; j <= m; j ++) {     //枚举体积
            cin >> w[i][j];
            for (int k = 0; k <= j; k ++)   //枚举决策，第i组物品分配多少台机器
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);  //状态转移方程
        }
    
    cout << f[n][m] << endl;    //最大价值
    
    int j = m;  //求具体方案，初始体积为m
    for (int i = n; i; i --)    //f[n][m]为答案，故从后往前推
        for (int k = 0; k <= j; k ++)   //看第i个公司分配多少台机器
            if (f[i][j] == f[i - 1][j - k] + w[i][k]) {     //找到答案
                way[i] = k;     //更新way[i]
                j -= k;     //更新j
                break;  //看下一个公司
            }
            
    
    for (int i = 1; i <= n; i ++) cout << i << " " << way[i] << endl;   //输出具体方案
    
    
    
    return 0;
}