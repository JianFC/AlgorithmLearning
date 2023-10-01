#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;    //1068. 环形石子合并

const int N = 410, INF = 0x3f3f3f3f;  //枚举2N长度的链

int n;
int w[N], s[N];     //w[i]存储重量，s[i]前缀和数组
int f[N][N], g[N][N];    //f[l][r]表示将[l, r]区间的石子合并的所有方案的最小值, g最大值

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) { //从下标1开始，便于求前缀和
        cin >> w[i];
        w[i + n] = w[i];    //复制该链到末尾
    }
    
    for (int i = 1; i <= n * 2; i ++) s[i] = s[i - 1] + w[i];   //前缀和
    
    memset(f, 0x3f, sizeof f);  //初始化f，求最小值，初始化正无穷
    memset(g, -0x3f, sizeof f);  //最大值，初始化为负无穷
    
    for (int len = 1; len <= n; len ++)     //枚举长度，只求长度为n的区间极值，不用枚举至2n
        for (int l = 1; l + len - 1 <= 2 * n; l ++) {     //枚举左边界
            int r = l + len - 1;    //右边界
            
            if (len == 1) f[l][r] = g[l][r] = 0;    //长度为1时，合并得分为0
            else {      //在else中做
                for (int k = l; k < r; k ++) {  //枚举分界点
                    f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);    //求最小值
                    g[l][r] = max(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);    //求最大值
                }
            }
        }
        
    int minv = INF, maxv = -INF;
    for (int i = 1; i <= n; i ++) {
        minv = min(minv, f[i][i + n - 1]);  //找出所有长度为n的区间中的最小值
        maxv = max(maxv, g[i][i + n - 1]);  //找出最大值
    }
    
    cout << minv << endl << maxv << endl;

    return 0;
}