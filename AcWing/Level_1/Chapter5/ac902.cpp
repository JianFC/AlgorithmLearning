#include <iostream>
#include <algorithm>

using namespace std;        //AcWing 902. 最短编辑距离

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];    //f[i][j]表示将a[1~i]变成b[1~j]的操作方式中操作次数的最小值

int main(void) {    
    scanf("%d%s", &n, a + 1); //使用到了i-1
    scanf("%d%s", &m, b + 1);

    //根据实际意义初始化边界情况
    for (int i = 0; i <= m; i ++) f[0][i] = i;   //在a中插入字符操作
    for (int i = 0; i <= n; i ++) f[i][0] = i;   //在a中删除字符操作

    //递推方程实现
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }

    cout << f[n][m] << endl;

    return 0;
}
