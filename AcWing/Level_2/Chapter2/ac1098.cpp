#include <iostream>
#include <algorithm>
#include <cstring>      //1098. 城堡问题

#define x first     //方便pair
#define y second

using namespace std;

typedef pair<int, int> PII;     //存储坐标

const int N = 55, M = N * N;

int n, m;
int g[N][N];    //存储地图
PII q[M];       //BFS所用队列
bool st[N][N];  //BFS判重数组

int bfs(int sx, int sy) {
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};   //按照西北东南定义，便于直接二进制判断是否有墙
    
    int hh = 0, tt = 0;     //初始一个点在队列中
    q[0] = {sx, sy};
    st[sx][sy] = true;        //更新st
    int area = 0;           //记录连通块的面积
    
    while (hh <= tt) {
        PII t = q[hh ++];   //取出对头
        area ++;        //统一更新area
        
        for (int i = 0; i < 4; i ++) {  //遍历方向向量
            int a = t.x + dx[i], b = t.y + dy[i];   //计算下一步的位置
            if (a < 0 || a >= n || b < 0 || b >= m) continue;   //越界
            if (st[a][b]) continue;     //已经走过
            if (g[t.x][t.y] >> i & 1) continue;     //(t.x, t.y) -> (a, b)之间存在墙，此处二进制优化
            
            q[++ tt] = {a, b};  //判掉所有非法情况后入队
            st[a][b] = true;        //更新st数组
        }
    }
    
    return area;        //返回连通块的面积
}

int main() {
    cin >> n >> m;  //输入比较少
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            cin >> g[i][j];     //读入地图
            
    int cnt = 0, area = 0;      //cnt表示连通块的数量，area表示最大面积
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            if (!st[i][j]) {    //该点没有被搜过
                area = max(area, bfs(i, j));    //bfs(i, j)返回该连通块的面积
                cnt ++;     //维护cnt数量
            }
            
    cout << cnt << endl << area << endl;
    
    return 0;
}