#include <iostream>
#include <algorithm>

using namespace std;    //AcWing 1027. 方格取数

const int N = 15;

int n;
int w[N][N];        //存储矩阵
int f[N * 2][N][N];   //f[k][i1][i2], k = i1 + j1 = i2 + j2, k表示当前走到的位置的横纵坐标之和

int main() {    
    scanf("%d", &n);

    int a, b, c;
    while (cin >> a >> b >> c, a || b || c) w[a][b] = c;        //输入数据

    for (int k = 2; k <= n + n; k ++)   //循环k
        for (int i1 = 1; i1 <= n; i1 ++)        //第一条路径i
            for (int i2 = 1; i2 <= n; i2 ++) {      //第二条路径i
                int j1 = k - i1, j2 = k - i2;       //求出两条路径的坐标
                
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) { //判断两个j的合法性
                    int t = w[i1][j1];          //最终重合时只需要加上(i1, j1)
                    if (i1 != i2) t += w[i2][j2];   //最终格子不重合，额外加上(i2, j2)的权值
                    
                    int &x = f[k][i1][i2];  //通过引用简化代码
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);   //第一类
                    x = max(x, f[k - 1][i1 - 1][i2] + t);     //第二类
                    x = max(x, f[k - 1][i1][i2 - 1] + t);     //第三类
                    x = max(x, f[k - 1][i1][i2] + t);           //第四类
                }
            }

    printf("%d\n", f[n + n][n][n]);

    return 0;
}