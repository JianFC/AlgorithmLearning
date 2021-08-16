#include <iostream>
#include <conio.h>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {
    if (u == n) {
        for (int i=0; i<n; i++) puts(g[i]);
        puts("");
        return;
    }
    
    for (int i=0; i<n; i++) {
        if (!col[i] && !dg[u+i] && !udg[u-i+n]) {
            g[u][i] = 'Q';
            col[i] = dg[u+i] = udg[u-i+n] = true;
            dfs(u+1);
            //恢复现场
            g[u][i] = '.';
            col[i] = dg[u+i] = udg[u-i+n] = false;
        }
    }
}

int main(void) {
    scanf("%d", &n);
    
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) 
            g[i][j] = '.';
    
    dfs(0);
    
    _getch();
    return 0;
}