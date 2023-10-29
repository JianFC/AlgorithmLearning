#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //188. 武士风度的牛

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 155, M = N * N;

int n, m;
char g[N][N];   //存储地图
PII q[M];       //BFS队列
int dist[N][N];     //记录K点到每个点的最短距离，同时可完成st数组功能

int bfs() {
    //日字形跳的8个方向向量
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    int sx, sy;     //找出k的位置
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            if (g[i][j] == 'K')
                sx = i, sy = j;     //起点位置
                
    int hh = 0, tt = 0;
    q[0] = {sx, sy};    //起点入队
    
    memset(dist, -1, sizeof dist);      //初始化dist
    dist[sx][sy] = 0;       //更新起点dist
    
    while (hh <= tt) {
        PII t = q[hh ++];   //取队头
        
        for (int i = 0; i < 8; i ++)
            for (int j = 0; j < 8; j ++) {
                int a = t.x + dx[i], b = t.y + dy[i];
                
                if (a < 0 || a >= n || b < 0 || b >= m) continue;   //越界
                if (g[a][b] == '*') continue;       //位置非法
                if (dist[a][b] != -1) continue;     //该点已经走过
                
                if (g[a][b] == 'H') return dist[t.x][t.y] + 1;      //走到终点
                
                dist[a][b] = dist[t.x][t.y] + 1;    //不是终点，更新(a, b)的dist值
                q[++ tt] = {a, b};      //(a, b)入队
            }
    }
    
    return -1;      //不会执行，保证代码完整性
}

int main() {
    cin >> m >> n;  //注意输入顺序，规模较小，可以用cin
    for (int i = 0; i < n; i ++) cin >> g[i];       //读入字符串
    
    cout << bfs() << endl;
    
    return 0;
}