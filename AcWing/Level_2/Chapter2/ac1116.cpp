#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1116. 马走日

const int N = 10;

int n, m;
bool st[N][N];      //存储每个状态中棋盘的点的情况
int ans;    //存储全局方案数量

//日字形方向向量
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void dfs(int x, int y, int cnt) {   //cnt表示已经走过的点的数量
    if (cnt == n * m) {
        ans ++;     //找到一种方案
        return;
    }
    
    st[x][y] = true;    //更新st
    for (int i = 0; i < 8; i ++) {
        int a = x + dx[i], b = y + dy[i];
        
        if (a < 0 || a >= n || b < 0 || b >= m) continue;   //越界
        if (st[a][b]) continue;     //该点已经走过
        
        dfs(a, b, cnt + 1);     //走到下一个点
    }
    
    st[x][y] = false;   //外部搜索注意恢复现场
}

int main() {
    int T;
    cin >> T;
    
    while (T --) {
        int x, y;
        cin >> n >> m >> x >> y;
        
        //由于外部搜索需要恢复现场，st数组可以不用清空
        ans = 0;    //清空ans
        dfs(x, y, 1);   //第三个参数表示走过的点的数量，用于判断是否走到结束状态
        printf("%d\n", ans);
    }
    
    return 0;
}