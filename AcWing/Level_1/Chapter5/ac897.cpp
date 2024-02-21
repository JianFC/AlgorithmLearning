#include <iostream>

using namespace std;    //AcWing 897. 最长公共子序列

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];    //f[i][j]表示所有在a前i个字母中出现，且在b前j个字母中出现的公共子序列

int main(void) {    
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);    //需用到i - 1与j - 1，所以从第1个位置开始存储

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }

    cout << f[n][m] << endl;

    return 0;
}
