#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;    //1064. 小国王

typedef long long LL;   //数据较大，会溢出int

const int N = 12, M = 1 << 10, K = 110;

int n, m;
vector<int> state;  //存储每一行所有合法状态
int id[M], cnt[M];  //id[i]存储每个合法状态i在state中的下标，cnt存储每个合法状态i中1的数量
vector<int> head[M];    //存储每个合法状态能够转移到的状态
LL f[N][K][M];     //f[i][j][s]表示已经摆了前i排，摆了j个国王，并且第i行摆放状态时s的所有方案的集合

bool check(int s) {     //检查状态s是否存在相邻的两个1
    for (int i = 0; i < n; i ++)
        if ((s >> i & 1) && (s >> i + 1 & 1))   
            return false;   //存在相邻的两个1
    return true;    //不存在相邻的两个1
}

int count(int s) {  //计算状态s中1的数量
    int res = 0;
    for (int i = 0; i < n; i ++) res += (s >> i & 1);
    return res;
}

int main() {
    cin >> n >> m;
    
    //预处理状态
    for (int i = 0; i < 1 << n; i ++)      //二进制枚举每一行所有状态
        if (check(i)) {
            state.push_back(i);
            id[i] = state.size() - 1;   //更新id数组
            cnt[i] = count(i);  //计算i中1的数量，即摆放的国王的数量
        }
        
    //预处理所有合法状态能转移到的状态
    for (int i = 0; i < state.size(); i ++)     //枚举第一个状态
        for (int j = 0; j < state.size(); j ++) {       //枚举第二个状态
            int a = state[i], b = state[j];     //取出两个合法状态
            if ((a & b) == 0 && check(a | b))   //注意条件
                head[i].push_back(j);       //b状态能够转移到a状态，注意存储的是下标
        }
        
    f[0][0][0] = 1;     //初始化前i行，没有摆国王，状态位0的f
    for (int i = 1; i <= n + 1; i ++)   //枚举每一行，trick：多枚举一行，答案即为f[n + 1][m][0]，省去遍历
        for (int j = 0; j <= m; j ++)   //枚举国王数量
            for (int a = 0; a < state.size(); a ++)     //枚举每一行所有合法状态
                for (int b: head[a]) {  //枚举其能转移到的状态
                    int c = cnt[state[a]];  //第i行有多少个1
                    if (j >= c)
                        f[i][j][state[a]] += f[i - 1][j - c][state[b]]; //状态转移方程
                }
    
    // LL res = 0;
    // for (int i = 0; i < state.size(); i ++) res += f[n][m][state[i]];
    // cout << res << endl;
    
    cout << f[n + 1][m][0] << endl;     //trick：多枚举一行，答案即为f[n + 1][m][0]，省去遍历
        
    return 0;
}