#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;

int n, m;
int h[N][N];    //高度
int f[N][N];    //f[i][j]所有从(i, j)开始滑的路径集合中长度的最大值

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

//返回每个状态的值
int dp(int x, int y) {      //AcWing 901. 滑雪
    int &v = f[x][y];   //用引用代替f[x][y];

    //记忆化搜索剪枝
    if (v != -1) return v;  

    v = 1;  //初始化f[x][y]
    //根据递推方程求出四个方向中最大值
    for (int i = 0; i < 4; i++) {   //注意循环次数qaq
        int a = x + dx[i], b = y + dy[i];
        //约束条件
        if (a >= 1 && a <= n && b >= 1 && b <= m && h[a][b] < h[x][y])
            v = max(v, dp(a, b) + 1);
    }

    return v;
}

int main(void) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &h[i][j]);

    memset(f, -1, sizeof f);    //记忆化搜索初始化，表示每个状态都还没被算过

    int res = 0;    //存储答案，全局最长滑雪长度
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res = max(res, dp(i, j));    //dp(i, j)两个作用
                                        //作用1：求出f[i][j]
                                        //作用2：递归求出路径上其他点的f[ii][jj]

    printf("%d\n", res);

    return 0;
}