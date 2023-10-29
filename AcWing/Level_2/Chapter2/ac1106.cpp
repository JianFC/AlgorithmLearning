#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1106. 山峰和山谷

#define x first
#define y second

typedef pair<int, int> PII;     //存储点

const int N = 1010, M = N * N;

int n;
int h[N][N];    //存储地图
PII q[M];       //BFS所用队列
bool st[N][N];      //BFS判重数组

void bfs(int sx, int sy, bool& is_higher, bool& is_lower) {     //引用返回
    int hh = 0, tt = 0;
    q[0] = {sx, sy};    //初始队列中有一个点
    st[sx][sy] = true;  //更新st
    
    while (hh <= tt) {
        PII t = q[hh ++];   //取对头
        
        //八连通，循环实现
        for (int i = t.x - 1; i <= t.x + 1; i ++)   //注意<=
            for (int j = t.y - 1; j <= t.y + 1; j ++) {
                if (i == t.x && j == t.y) continue;     //特判掉中心点
                if (i < 0 || i >= n || j < 0 || j >= n) continue;   //越界
                
                if (h[i][j] != h[t.x][t.y]) {   //(t.x, t.y)为连通块边界，可扩展题目求周长
                    if (h[i][j] > h[t.x][t.y]) is_higher = true;    //更新标记
                    else is_lower = true;   //更新标记
                }
                else if (!st[i][j]) {   //(i, j)位于连通块内，只有没有被遍历时才能进入
                    q[++ tt] = {i, j};  //(i, j)入队
                    st[i][j] = true;    //更新st数组
                }
            }
    }
    
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            scanf("%d", &h[i][j]);      //输入地图
            
    int peak = 0, valley = 0;   //山峰的数量和山谷的数量
    for (int i = 0; i < n; i ++)    //对每个点flood fill
        for (int j = 0; j < n; j ++)
            if (!st[i][j]) {    //该点没有被走过
                bool is_higher = false, is_lower = false;   //存储边界外有没有比该连通块高的or低的连通块
                // 函数需要返回两个值is_higher, is_lower，通过引用实现
                bfs(i, j, is_higher, is_lower);
                if (!is_higher) peak ++;    //没有比其高的，更新peak，trick：反向更新更简洁
                if (!is_lower) valley ++;   //没有比其矮的
            }
            
    printf("%d %d\n", peak, valley);
    
    return 0;
}