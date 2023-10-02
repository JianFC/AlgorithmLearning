#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;        //AcWing 91. 最短Hamilton路径

const int N = 21, M = 1 << N;

int n;
int w[N][N];
int f[M][N];    //f[i][j]表示所有从0号点走到j号点，走过的所有点是状态i的路径最小值

int main(void) {    
    scanf("%d", &n);

    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            scanf("%d", &w[i][j]);

    memset(f, 0x3f, sizeof f);  //除0号点，其余所有点初始化为正无穷
    f[1][0] = 0;    //从0号点走到0号点，状态是0..01，故初始化为f[1][0]=0;

    for (int i = 0; i < 1 << n; i ++)  //从0开始枚举所有二进制状态
        for (int j = 0; j < n; j ++) //具体考虑每一个状态的各个二进制位
            if (i >> j & 1)     //当前状态第j个点已经走过
                for (int k = 0; k < n; k ++)  //枚举第j个点前一个走过的点，即倒数第二个走过的点
                    if ((i - (1 << j)) >> k & 1)  //从i中除去j，并且第k个点走过
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);

    cout << f[(1 << n) - 1][n - 1] << endl;   //输出答案，所有点走过，且终点是n-1

    return 0;
}