#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;        //327. 玉米田

const int N = 14, M = 1 << 12, mod = 1e8;

int n, m;
int g[N];   //g[i]表示第i行的土地能否种植状态，0表示能种，1表示不能种，存储二进制
vector<int> state;  //存储所有合法状态
vector<int> head[M];    //存储所有合法状态能够转移到的状态
int f[N][M];    //f[i][s]表示所有已经摆了前i行，且第i行状态是s的所有方案的集合

bool check(int s) {
    for (int i = 0; i < m; i ++)
        if ((s >> i & 1) && (s >> i + 1 & 1))   //存在相邻两个1
            return false;
    return true;
}

int main() {
    cin >> n >> m;
    
    //读入玉米田情况
    for (int i = 1; i <= n; i ++)   //从第一行开始
        for (int j = 0; j < m; j ++) {
            int t;
            cin >> t;
            g[i] += !t << j;    //0表示能种，1表示不能种，方便后面进行状态判断
        }
        
    for (int i = 0; i < 1 << m; i ++)   //求每一行的所有合法状态，注意m代表列数
        if (check(i))
            state.push_back(i);
            
            
    for (int i = 0; i < state.size(); i ++) //枚举所有合法状态能到的状态
        for (int j = 0; j < state.size(); j ++) {
            int a = state[i], b = state[j];
            if ((a & b) == 0)
                head[i].push_back(j);   //j能够走到i
        }
    
    f[0][0] = 1;    //初始化
    for (int i = 1; i <= n + 1; i ++)   //trick：枚举到n + 1
        for (int a = 0; a < state.size(); a ++)     //枚举所有合法状态
            for (int b: head[a]) {       //枚举前一行的合法状态
                if (g[i] & state[a]) continue;  //该状态中有玉米不能种下，跳过
                f[i][state[a]] = (f[i][state[a]] + f[i - 1][state[b]]) % mod;    //可以用下标a代替state[a]，一一对应
            }
            
    cout << f[n + 1][0] << endl;    //trick，输出n + 1层的0状态，省去遍历
    
    return 0;
}