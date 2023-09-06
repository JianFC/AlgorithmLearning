#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-6;

int n;
double a[N][N];

int gauss() {       //AcWing 883. 高斯消元解线性方程组
    int c, r;   //c表示列，r表示行

    for (c = 0, r = 0; c < n; c++) {
        int t = r;

        //找出第c列绝对值最大的一行
        for (int i = r; i < n; i++)
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        //如果最大值是0，结束本次循环，跳到下一列
        if (fabs(a[t][c]) < eps) continue;

        //将该行换至当前最上面
        for (int i = c; i < n + 1; i++) swap(a[t][i], a[r][i]);
        //将该行第一个非零数化为1，注意行数已经变为r
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];

        //将该行之下所有行的第c列消为0
        for (int i = r + 1; i < n; i++) 
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c]; //a[i][c]为乘的系数

        r++;
    }

    if (r < n) {    //无穷多解或者无解
        for (int i = r; i < n; i++)     //从第r行开始看
            if (fabs(a[i][n]) > eps)
                return 2;   //0 = 非零，无解

        return 1;   // 无穷多组解
    }

    //若有解则从最后一行的方程开始求解
    for (int i = n - 1; i >= 0; i--)  //从最后一行开始
        for (int j= i + 1; j < n; j++)   
            //最终结果为a[i][n]-主元外的所有系数a[i][j]*与系数对应的xj的值即a[j][n]
            a[i][n] -= a[i][j]*a[j][n];

    return 0;   //唯一解
}

int main(void) {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)    //行
        for (int j = 0; j < n + 1; j++)   //列，循环n+1次，a[i][n]存储等号右侧常数
            scanf("%lf", &a[i][j]); //注意输入格式控制！

    int t = gauss();

    if (t == 0) {   //存在唯一解
        for (int i = 0; i < n; i++) printf("%.2f\n", a[i][n]);
    }
    else if (t == 1) puts("Infinite group solutions");
    else puts("No solution");

    return 0;
}