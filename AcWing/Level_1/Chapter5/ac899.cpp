#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;    //AcWing 899. 编辑距离

const int N = 15, M = 1010;

int n, m;
char str[M][N];
int f[N][N];

int edit_dist(char *a, char *b) {       
    int la = strlen(a + 1), lb = strlen(b + 1);

    //初始化边界
    for (int i = 0; i <= lb; i ++) f[0][i] = i;
    for (int i = 0; i <= la; i ++) f[i][0] = i;

    for (int i = 1; i <= la; i ++)
        for (int j = 1; j <= lb; j ++) {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }

    return f[la][lb];
}

int main(void) {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i ++) scanf("%s", str[i] + 1);

    while (m --) {
        char s[N];
        int limit;
        scanf("%s%d", s + 1, &limit);

        int res = 0;    //记录有多少个字符串满足限制条件
        for (int i = 0; i < n; i ++)
            if (edit_dist(str[i], s) <= limit)
                res++;

        printf("%d\n", res);
    }

    return 0;
}