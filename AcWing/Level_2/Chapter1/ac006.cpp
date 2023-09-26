#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;    //6. 多重背包问题 III

const int N = 20010;    //背包最大容积

int n, m;   //物品总数和背包容积
int hh, tt = -1;    //单调队列队头和队尾
int f[N], g[N], q[N];   //f[N],g[N]优化后的状态数组，q[N]单调队列，存储f[i]数组的下标

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i ++) {      //枚举每个物品
        int v, w, s;
        cin >> v >> w >> s;
        
        memcpy(g, f, sizeof f);     //滚动数组，存储上一层状态
        
        for (int j = 0; j < v; j ++) {  //枚举余数，保证每个背包容积的f都算正确
            hh = 0, tt = -1;    //重置队头队尾
            
            for (int k = j; k <= m; k += v) {   //枚举f[m - k * v]
                if (hh <= tt && q[hh] < k - s * v) hh ++;   //单调队列容量已满，队头元素出队
                
                //保证单调队列性质，减去(k - j) / v * w保证每一项和状态转移方程保持一致
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt --;     
                q[++ tt] = k;   //下标入队
                
                f[k] = g[q[hh]] + (k - q[hh]) / v * w;  //更新f[k],注意减的项
            }    
        }
    }
    
    cout << f[m] << endl;
    
    return 0;
}
