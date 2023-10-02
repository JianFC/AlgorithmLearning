#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //320. 能量项链

const int N = 210;  //破环成链，开两倍的空间

int n;
int w[N];   //w[i]存储能量值
int f[N][N];    //f[L][R]表示将[L, R]合并成一个珠子的方案的能量最大值

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> w[i];
        w[i + n] = w[i];    //将链在末尾复制一遍
    }
    
    for (int len = 3; len <= n + 1; len ++)     //枚举长度，从len = 3开始枚举
        for (int l = 1; l + len - 1 <= 2 * n; l ++) {    //枚举左端点
            int r = l + len - 1;    //区间右端点
            for (int k = l + 1; k < r; k ++)    //枚举分界线
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r]);     //状态转移方程
        }
        
    int res = 0;
    for (int i = 1; i <= n; i ++) res = max(res, f[i][i + n]);  //枚举所有长度为n + 1的区间，找最大值
    
    cout << res << endl;
    
    return 0;
}