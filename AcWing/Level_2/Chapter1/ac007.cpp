#include <iostream>
#include <algorithm>

using namespace std;    //7. 混合背包问题

const int N = 1010;

int n, m;
int f[N];   //背包问题状态定义方式，优化掉第一维

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i ++) {
        int v, w, s;
        cin >> v >> w >> s;
        if (s == 0) {   //完全背包
            for (int j = v; j <= m; j ++)
                f[j] = max(f[j], f[j - v] + w);     //完全背包问题状态转移方程
        }
        else {      //01背包是特殊的完全背包问题
            if (s == -1) s = 1;     //将01背包问题改为多重背包问题
            
            //多重背包进行二进制优化，转为01背包问题
            for (int k = 1; k <= s; k *= 2) {    //k每次倍增 
                for (int j = m; j >= k * v; j --)   // 01背包问题求解
                    f[j] = max(f[j], f[j - k * v] + k * w);
                
                s -= k;     //更新剩余数量
            }
            
            if (s) {     //最后还有剩余，则再进行一次01背包
                for (int j = m; j >= s * v; j --)
                    f[j] = max(f[j], f[j - s * v] + s * w);
            }
        }
    }
    
    cout << f[m] << endl;
    
    return 0;
}