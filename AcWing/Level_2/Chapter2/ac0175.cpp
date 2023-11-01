#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>

using namespace std;        //175. 电路维修

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 510;

int n, m;
char g[N][N];   //存储线缆矩阵
int dist[N][N];     //存储起点到其他格点的最短距离
bool st[N][N];      //由于队列中一个点可能存在多个记录，st[i][j]记录格点的最短距离是否已经确定

int bfs() {
    memset(dist, 0x3f, sizeof dist);        //多组测试数据，初始化
    memset(st, 0, sizeof st);
    
    deque<PII> q;   //定义双端队列
    q.push_back({0, 0});    //起点入队
    dist[0][0] = 0;     //更新起点dist
    
    //方向和转换向量
    char cs[5] = "\\/\\/";      //该格点到周围四个点所需要的线缆形状，\\中第一个\为禁止转义
    int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};     //该格点能通过线缆到的4个点
    int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};     //该格点周围4条线缆在g中的坐标
    
    while (q.size()) {
        PII t = q.front();  //取队头
        q.pop_front();      //队头弹出
        
        int x = t.x, y = t.y;   //简化书写
        if (x == n && y == m) return dist[n][m];    //注意终点是(n, m)，最短距离已经确定
        
        if (st[x][y]) continue;     //该点最小距离已经确定，跳过
        st[x][y] = true;        //更新st
        
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];   //能到的点
            if (a < 0 || a > n || b < 0 || b > m) continue;     //越界，注意格子矩阵边界为n和m
            
            int ga = x + ix[i], gb = y + iy[i];     //(x, y)和(a, b)组成的线缆在g中的位置
            int w = (g[ga][gb] != cs[i]);    //判断(x, y)到(a, b)点的边的权重，不同为1，相同为0
            
            int d = dist[x][y] + w;     //暂存到(a, b)的距离
            if (d < dist[a][b]) {
                dist[a][b] = d;     //更新到(a, b)的最短距离
                
                if (w) q.push_back({a, b});     //双端队列，边权为1，放到队尾
                else q.push_front({a, b});  //边权为0，放到队头
            }
        }
    }
    
    return -1;      //不会被执行
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i ++) scanf("%s", g[i]);     //读入线缆矩阵
        
        if (n + m & 1) puts("NO SOLUTION");     //当终点横纵坐标之和为奇数时，一定无解
        else printf("%d\n", bfs());
    }
    
    return 0;
}

