#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;        //292. 炮兵阵地

const int N = 110, M = 1 << 10;

int n, m;
int g[N];   //g[i]存储第i行的状态
vector<int> state;  //存储所有合法状态
int cnt[M];     //记录状态i中1的数量
int f[2][M][M]; //滚动数组优化空间，f[i][j][k],前i行，第i - 1行状态j，第i行状态k

bool check(int s) {
    for (int i = 0; i < m; i ++)
        //1后面连续两个格子内不能有0
        if ((s >> i & 1) && ((s >> i + 1 & 1) | (s >> i + 2 & 1)))
            return false;
    return true;
}

int count(int s) {
    int res = 0;
    for (int i = 0; i < m; i ++) res += s >> i & 1;
    return res;
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < m; j ++) {
            char c;
            cin >> c;
            if (c == 'H') g[i] += 1 << j;   //更新g数组
        } 
    
    for (int i = 0; i < 1 << m; i ++)
        if (check(i)) {
            state.push_back(i);     //加入合法状态
            cnt[i] = count(i);  //更新cnt数组
        }
        
    //求最大值已经默认初始化为0
    for (int i = 1; i <= n + 2; i ++)   //枚举第一维
        for (int j = 0; j < state.size(); j ++)     //枚举第i - 1行的状态
            for (int k = 0; k < state.size(); k ++)     //枚举第i行的状态
                for (int u = 0; u < state.size(); u ++) {     //枚举第i - 2行的状态 
                    int a = state[j], b = state[k], c = state[u];
                    if (a & b | a & c | b & c) continue;    //不等于0时，跳过
                    if (g[i - 1] & a | g[i] & b) continue;  //不等于0时，跳过
                    // i & 1改为滚动数组
                    f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][u][j] + cnt[b]);  //状态转移方程
                }
    
    cout << f[n + 2 & 1][0][0] << endl;     //trick，多枚举两行
        
    return 0;
}