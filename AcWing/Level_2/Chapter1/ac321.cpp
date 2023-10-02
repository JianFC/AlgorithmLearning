#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;        //321. 棋盘分割

const int N = 15, M = 9;
const double INF = 1e9;

int n, m = 8;
int s[M][M];    //存储棋盘，采用二维前缀和存储
double f[M][M][M][M][N];    //f[x1][y1][x2][y2][k]表示将子矩阵(x1, y1), (x2, y2)切分成k部分的方案的属性最小值
double X;   //棋盘平均值

double get(int x1, int y1, int x2, int y2) {
    //前缀和公式,注意精度转换
    double sum = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] - X;    
    return sum * sum / n;   
}

double dp(int x1, int y1, int x2, int y2, int k) {  //记忆化搜索实现dp
    double &v = f[x1][y1][x2][y2][k];   //简化书写
    if (v >= 0) return v;    //已经搜过，直接返回
    if (k == 1) return get(x1, y1, x2, y2);     //当k = 1时，直接计算(x1, y1)(x2, y2)围成的属性值
    
    v = INF;    //初始化该格为INF
    for (int i = x1; i < x2; i ++) {    //横着切，(x1, y1)代表的格子，不是点，有面积，从x1开始枚举
        v = min(v, dp(x1, y1, i, y2, k - 1) + get(i + 1, y1, x2, y2));  //取上面部分继续切
        v = min(v, dp(i + 1, y1, x2, y2, k - 1) + get(x1, y1, i, y2));  //取下面部分继续切
    }
    for (int i = y1; i < y2; i ++) {    //竖着切，从y1开始枚举
        v = min(v, dp(x1, y1, x2, i, k - 1) + get(x1, i + 1, x2, y2));  //取左边部分继续切
        v = min(v, dp(x1, i + 1, x2, y2, k - 1) + get(x1, y1, x2, i));  //取右边部分继续切
    }
    
    return v;   //返回答案
}

int main() {
    cin >> n;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= m; j ++) {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];     //二维前缀和初始化
        }
    
    memset(f, -1, sizeof f);    //记忆化搜索前，初始化f数组
    X = (double)s[m][m] / n;    //求出x(bar)，注意精度转换
    
    printf("%.3lf\n", sqrt(dp(1, 1, 8, 8, n)));     //输出答案、
    
    return 0;
}