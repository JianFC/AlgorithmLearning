//区间DP
// 既然让我求解在一个区间上的最优解，那么我把这个区间分割成一个个小区间，
// 求解每个小区间的最优解，再合并小区间得到大区间即可。所以在代码实现上，
// 我可以枚举区间长度len为每次分割成的小区间长度（由短到长不断合并），内层枚举该长度下可以的起点，
// 自然终点也就明了了。然后在这个起点终点之间枚举分割点，求解这段小区间在某个分割点下的最优解。

// 断环成链
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 210;   //注意此处n的取值大于题目n取值的2倍
int w[maxn], sum[maxn]; //sum数组为前缀和
int dp1[maxn][maxn];    //求最小得分    
int dp2[maxn][maxn];    //求最大得分
int n;
int minn = 0x7fffffff, maxx = 0;

int main(void) {
    cin >> n;
    memset(dp1, 63, sizeof(dp1));
    fp(i, 1, n) {
        cin >> w[i]; 
        w[i+n]=w[i];
    }
    //求前缀和与初始化
    fp(i, 1, 2*n) {
        sum[i] = w[i]+sum[i-1];   
        dp1[i][i] = 0;
    }

    for (int len=2; len<=n; len++) {    //枚举区间长度
        for (int i=1; i+(len-1)<2*n; i++) {   //枚举起点
            int ends = i+(len-1);   //计算终点
            for (int k=i; k<ends; k++) {    //枚举合并区间的断电
                dp1[i][ends] = min(dp1[i][ends], dp1[i][k]+dp1[k+1][ends]+(sum[ends]-sum[i-1]));
                dp2[i][ends] = max(dp2[i][ends], dp2[i][k]+dp2[k+1][ends]+(sum[ends]-sum[i-1]));
            }
        }
    }

    for (int i=1; i<=n; i++) {
        minn = min(minn, dp1[i][i+n-1]);
        maxx = max(maxx, dp2[i][i+n-1]);
    }

    cout << minn << endl << maxx;


    _getch();
    return 0;
}
