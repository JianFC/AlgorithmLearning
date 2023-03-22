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
char s[200];
int dp[200][200];   //dp[i][j]表示第i到第j个字符中最长括号匹配的长度

int main(void) {
    cin>>s;
    while (strcmp(s, "end")!=0) {
        memset(dp, 0, sizeof(dp));  //dp初始化
        int slen = strlen(s);
        for (int len=2; len<=slen; len++) { //枚举区间长度
            for (int i=0; i+(len-1)<=slen-1; i++) { //枚举起点位置
                int j = i+(len-1);   //终点位置

                if ((s[i]=='('&&s[j]==')') || (s[i]=='['&&s[j]==']')) {
                    dp[i][j] = dp[i+1][j-1]+2;  //状态转移方程1
                }

                for (int k=i; k<j; k++) {   //枚举区间断点k
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);  //状态转移方程2
                }
            }
        }

        cout << dp[0][slen-1] << endl;
        cin >> s;
    }


    _getch();
    return 0;
}
