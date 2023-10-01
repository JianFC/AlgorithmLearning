#include <iostream>
#include <algorithm>

using namespace std;    //282. 石子合并

const int N = 310, INF = 0x3f3f3f3f;

int n;
int s[N];   //前缀和数组
int f[N][N];    //f[i][j]表示将第i堆石子到第j堆石子合并成一堆石子的最小代价

int main(void) {    //AcWing 282. 石子合并
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++) scanf("%d", &s[i]);

    //处理前缀和
    for (int i = 1; i <= n; i ++) s[i] += s[i - 1];

    //首先枚举区间长度，且如果长度为1，则合并代价为0，故从len=2开始枚举
    for (int len = 2; len <= n; len ++)
        for (int i = 1; i + len - 1 <= n; i ++)  {   //枚举起点
            int l = i, r = i + len - 1;     //计算区间左端点和右端点
            f[l][r] = INF;      //初始化f[l][r]为较大值

            //若区间长度为0，则合并代价为0，因此可以直接从len=2开始枚举
            //if (len == 1) f[l][r] = 0;

            for (int k = l; k < r; k ++) //枚举分界线的位置l~(r-1)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);  //递推方程
        }

    cout << f[1][n] << endl;    //输出结果

    return 0;
}