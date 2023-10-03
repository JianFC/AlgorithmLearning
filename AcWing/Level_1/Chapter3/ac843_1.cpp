#include <iostream>

using namespace std;        //AcWing 843. n-皇后问题

const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N];  //dg对角线，udg反对角线，dg数量是n的二倍，所以N=20

//全排列搜索顺序
void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i ++) puts(g[i]);
        puts("");
        return ;
    }

    for (int i = 0; i < n; i ++) {
        if (!col[i] && !dg[i + u] && !udg[i - u + n]) {
            g[u][i] = 'Q';
            col[i] = dg[i + u] = udg[i - u + n] = true;
            dfs(u + 1);
            //恢复现场
            g[u][i] = '.';
            col[i] = dg[i + u] = udg[i - u + n] = false;
        }
    }
}

int main(void) {    
    scanf("%d", &n);

    for (int i = 0; i < n; i ++)
        for (int j = 0; j<n; j ++)
            g[i][j] = '.';

    dfs(0);

    return 0;
}
