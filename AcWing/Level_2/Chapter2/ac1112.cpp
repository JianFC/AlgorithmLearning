#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1112. 迷宫

const int N = 110;

int n;
char g[N][N];   //存储地图
bool st[N][N];      //判重数组，判断是否走过
int xa, ya, xb, yb;     //起点和终点坐标

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};     //方向向量

bool dfs(int x, int y) {
    if (g[x][y] == '#') return false;       //最后一个条件加在此处更保险
    if (x == xb && y == yb) return true;    //搜到了终点
    
    st[x][y] = true;    //该点已经走过
    for (int i = 0; i < 4; i ++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= n) continue;   //越界
        if (st[a][b]) continue; //已经走过
        
        if (dfs(a, b)) return true;     //如果该方向可以走到B，返回True
    }
    //不用恢复st，st表示该点已经走过
    
    return false;   //四个方向都不能走到B，返回false
}

int main() {
    int T;
    cin >> T;
    while (T --) {
        memset(st, 0, sizeof st);   //清空数组
        cin >> n;
        for (int i = 0; i < n; i ++) cin >> g[i];   //输入地图
        cin >> xa >> ya >> xb >> yb;
        
        if (dfs(xa, ya)) puts("YES");
        else puts("NO");
    }
    
    return 0;
}