#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //173. 矩阵距离

#define x first     //简化pair
#define y second

typedef pair<int, int> PII;     //存点

const int N = 1010, M = N * N;

int n, m;
char g[N][N];       //存储矩阵
PII q[M];       //多源BFS
int dist[N][N];     //每个点到最近起点的距离，同时完成st的功能

void bfs() {
    memset(dist, -1, sizeof dist);      //初始化dist
    
    int hh = 0, tt = -1;        //手动模拟队列，队列还未加入元素
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            if (g[i][j] == '1') {   //找出所有起点，加入队列，转换为单源BFS问题
                dist[i][j] = 0;     //更新起点的dist
                q[++ tt] = {i, j};      //将所有起点加入队列
            }
    
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};     //方向向量
    
    //正常bfs
    while (hh <= tt) {
        PII t = q[hh ++];   //取队头
        
        for (int i = 0; i < 4; i ++) {
            int a = t.x + dx[i], b = t.y + dy[i];   //下一个位置坐标
            
            if (a < 0 || a >= n || b < 0 || b >= m) continue;   //越界
            if (dist[a][b] != -1) continue;     //已经确定最小值
            
            dist[a][b] = dist[t.x][t.y] + 1;    //曼哈顿距离即为正常距离求法
            q[++ tt] = {a, b};      //扩展t，加入队列
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%s", g[i]);
    
    bfs();      //多源BFS转换为单源BFS
    
    for (int i = 0; i < n; i ++) {
        for (int j= 0; j < m; j ++) printf("%d ", dist[i][j]);
        puts("");
    }
    
    return 0;
}

