//区间DP
// 既然让我求解在一个区间上的最优解，那么我把这个区间分割成一个个小区间，
// 求解每个小区间的最优解，再合并小区间得到大区间即可。所以在代码实现上，
// 我可以枚举区间长度len为每次分割成的小区间长度（由短到长不断合并），内层枚举该长度下可以的起点，
// 自然终点也就明了了。然后在这个起点终点之间枚举分割点，求解这段小区间在某个分割点下的最优解。

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
//板子
inline void pattern(void) {
    int something;  //指代实际问题中状态转移方程中的除状态外的其他参数表达式
    const int n = 200;
    int dp[n][n];
    //初始化dp数组
    memset(dp, 63, sizeof(dp));
    for (int i=1; i<=n; i++) dp[i][i] = 0;    
    
    //核心代码
    for (int len=1; len<=n; len++) { //枚举区间长度
        for (int i=1; i+(len-1)<=n; i++) {  //枚举起点
            int ends = i+(len)-1;   //当区间长度为len时，与起点i对应的终点
            for (int k=i; k<ends; k++) {
                dp[i][ends] = min(dp[i][ends], dp[i][k]+dp[k+1][ends]+something);
            }

        }
    }
}

// 例题：CodeVs1048 石子合并
// 题目描述
// 有n堆石子排成一列，每堆石子有一个重量w[i], 每次合并可以合并相邻的两堆石子，一次合并的代价为两堆石子的重量和w[i]+w[i+1]。
// 问安排怎样的合并顺序，能够使得总合并代价达到最小。

// 输入描述
// 第一行一个整数n（n<=100）
// 第二行n个整数w1,w2…wn (wi <= 100)

// 输出描述
// 一个整数表示最小合并代价

// 样例输入
// 4
// 4 1 1 4

// 样例输出
// 18
const int maxn = 110;
int dp[maxn][maxn];
int w[maxn], sum[maxn]; //sum数组为前缀和
int n;

int main(void) {
    cin >> n;
    memset(dp, 63, sizeof(dp));    //注意当i!=j时，初始化dp[i][j]=INF;
    fp(i, 1, n) { 
        cin >> w[i]; 
        sum[i]=w[i]+sum[i-1]; 
        dp[i][i] = 0;   //初始化dp数组   
    }
    
    int ends;   //终点
    for (int len=2; len<=n; len++) {    //枚举长度
        for (int i=1; i+(len-1)<=n; i++) {  //枚举起点
            ends = i+(len-1);   //计算终点
            for (int k=i; k<ends; k++) {   //枚举k，k的范围为[起点, 终点)
                dp[i][ends] = min(dp[i][ends], dp[i][k]+dp[k+1][ends]+(sum[ends]-sum[i-1]));    //状态转移方程
            }
        }
    }

    cout << dp[1][n];

    _getch();
    return 0;
}
