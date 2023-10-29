#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1076. 迷宫问题

#define x first
#define y second

typedef pair<int, int> PII;     //存储点的坐标

const int N = 1010, M = N * N;

int n;
int g[N][N];    //存储地图
PII q[M];   //BFS队列
PII pre[N][N];      //pre[i][j]记录(i, j)前一个点是什么，同时完成st数组的功能

void bfs(int sx, int sy) {
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};   //方向向量
    
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    
    memset(pre, -1, sizeof pre);    //初始化pre数组为-1
    pre[sx][sy] = {0, 0};       //起点的pre任意设置，但不能为1
    
    while (hh <= tt) {
        PII t = q[hh ++];       //取对头
        
        for (int i = 0; i < 4; i ++)
            for (int j = 0; j < 4; j ++) {
                int a = t.x + dx[i], b = t.y + dy[i];   //下一个点坐标
                
                if (a < 0 || a >= n || b < 0 || b >= n) continue;   //判越界
                if (g[a][b]) continue;      //墙壁
                if (pre[a][b].x != -1) continue;    //pre完成st的功能，该点已经走过
                
                q[++ tt] = {a, b};  //(a, b)入队
                pre[a][b] = t;  //记录(a, b)从哪个点过来
            }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            scanf("%d", &g[i][j]);      //读入地图
    
    bfs(n - 1, n - 1);      //trick：从最后一个点开始往前搜，从而直接正向输出pre数组
    
    PII end(0, 0);      //从(0, 0)开始输出到(n - 1, n - 1)
    
    while (true) {
        printf("%d %d\n", end.x, end.y);
        if (end.x == n - 1 && end.y == n - 1) break;    //路径输出完毕
        end = pre[end.x][end.y];    //走到(end.x, end.y)的上一个点
    }
    
    return 0;
}