#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1058. 股票买卖 V

const int N = 100010, INF = 0x3f3f3f3f;

int n;
int w[N];    //w[i]表示第i天的价格
int f[N][3];    //f[i][0]表示前i天，处于第1个状态的最大值，f[i][1]第二个状态，f[i][2]

int main() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    f[0][0] = f[0][1] = -INF, f[0][2] = 0;  //初始化
    
    for (int i = 1; i <= n; i ++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - w[i]); //状态0转移方程
        f[i][1] = f[i - 1][0] + w[i];  //状态2
        f[i][2] = max(f[i - 1][1], f[i - 1][2]);
    }
    
    printf("%d\n", max(f[n][1], f[n][2]));  //输出第一个和第二个状态的最大值
    
    return 0;
}
