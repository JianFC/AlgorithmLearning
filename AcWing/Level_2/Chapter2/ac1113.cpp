#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1113. 红与黑

const int N = 25;

int n, m;
char g[N][N];   //存储地图
bool st[N][N];      //判重数组

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int dfs(int x, int y) {     //DFS实现flood fill算法
    int cnt = 1;    //记录(x, y)所在的连通块中当前还未被搜过的点的数量
    
    st[x][y] = true;    //在一个整体中搜索，保证每个点只会被搜索一次，不需要恢复现场
    for (int i = 0; i < 4; i ++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m) continue;   //越界
        if (g[a][b] != '.') continue;   //不是黑点
        if (st[a][b]) continue;     //当前点已经走过
        
        cnt += dfs(a, b);   //更新cnt的值
    }
    
    return cnt;     //返回连通块的数量
}

int main() {
    while (cin >> m >> n, n || m) {     //注意是先输入列数，再输入行数
        memset(st, 0, sizeof st);   //多组数据，st数组初始化
        for (int i = 0; i < n; i ++) cin >> g[i];   //读入地图
        
        int x, y;   //找到起点
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                if (g[i][j] == '@') {
                    x = i, y = j;
                }
        
        cout << dfs(x, y) << endl;  //dfs返回x所在的连通块的数量
    }
    
    return 0;
}