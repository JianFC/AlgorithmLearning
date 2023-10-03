#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;    //1072. 树的最长路径

const int N = 10010, M = N * 2;     //无向图，边数 * 2

int n;
int h[N], e[M], w[M], ne[M], idx;   //邻接表存图
int ans;    //存储dfs搜到的直径答案

void add(int a, int b, int c) {      //加边函数
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

//DFS实现DP思想
int dfs(int u, int fa) {    //返回值是u向下的最长路径，fa是u的父节点，防止u往回走
    int dist = 0;   //u向下可以走的最长路径
    int d1 = 0, d2 = 0;     //d1向下走的最长路径，d2向下走的次长路径，初始化为0，如果有路径为负数则不选
    
    for (int i = h[u]; i != -1; i = ne[i]) {    //遍历u的所有儿子
        int j = e[i];
        if (j == fa) continue;  //防止向上走
        int d = dfs(j, u) + w[i];      //求出子树的最长路径
        dist = max(dist, d);    //更新dist
        
        if (d >= d1) d2 = d1, d1 = d;    //更新最大值和次大值
        else if (d > d2) d2 = d;    //当d1 > d > d2时，只更新d2
    }
    
    ans = max(ans, d1 + d2);    //更新全局最优解
    
    return dist;
}

int main() {
    cin >> n;
    
    memset(h, -1, sizeof h);    //初始化
    
    for (int i = 0; i < n - 1; i ++) {  // n - 1条边
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);     //无向图
    }
    
    dfs(1, -1);     //树是连通的，假设1号点为根节点，其父节点为-1
    
    cout << ans << endl;
    
    return 0;
}



