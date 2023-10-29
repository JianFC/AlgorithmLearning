#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1097. 池塘计数

#define x first     //简化pair的书写
#define y second

typedef pair<int, int> PII;     //用于存储坐标的队列

const int N = 1010, M = N * N;

int n, m;
char g[N][N];       //存储地图
PII q[M];       //BFS队列，最多可能有N * N个点，手动模拟
bool st[N][N];      //BFS一般都需要st数组判重

void bfs(int sx, int sy) {  //(sx, sy)为起点坐标，遍历该坐标形成的连通块，更新st
    int hh = 0, tt = 0;
    q[0] = {sx, sy};    //初始时队列中有一个点
    st[sx][sy] = true;      //更新st，防止重复走
    
    while (hh <= tt) {
        PII t = q[hh ++];   //取出对头
        
        //八连通一般暴力枚举周围八个点
        for (int i = t.x - 1; i <= t.x + 1; i ++)       //注意是 <=
            for (int j = t.y - 1; j <= t.y + 1; j ++) {
                if (i == t.x && j == t.y) continue;     //八连通判掉中心
                if (i < 0 || i >= n || j < 0 || j >= m) continue;   //判掉边界合法性
                if (g[i][j] == '.' || st[i][j]) continue;   //判掉不合法的点和已经走过的水洼
                
                q[++ tt] = {i, j};  //同一连通块的点入队
                st[i][j] = true;    //更新st数组
            }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%s", g[i]);     //输入地图
    
    int cnt = 0;    //存储flood fill找到的连通块数量
    for (int i = 0; i < n; i ++)    
        for (int j = 0; j < m; j ++)
            if (g[i][j] == 'W' && !st[i][j]) {      //对于每一个合法点进行flood fill算法
                bfs(i, j);  
                cnt ++;     //更新连通块数量
            }
            
    printf("%d\n", cnt);
    
    return 0;
}

