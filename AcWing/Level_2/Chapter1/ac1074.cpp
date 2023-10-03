#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;    //1074. 二叉苹果树

const int N = 110, M = N * 2;   //默认为无向图

int n, m;
int h[N], e[M], w[M], ne[M], idx;   
int f[N][N];    //f[i][j]表示在以i为根的子树中，选择j条边的最大价值

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int father) {
    for (int i = h[u]; ~i; i = ne[i]) {     //物品组
        int son = e[i];
        if (son == father) continue;    //无向图，跳过
        dfs(son, u);    //递归求出儿子节点信息
        
        for (int j = m; j >= 0; j --)   //分组背包问题，枚举体积，从m开始
            for (int k = 0; k + 1 <= j; k ++)      //枚举到j - 1，留1个体积给(u, son)
                //注意状态转移方程为j - k - 1，多减的1为(u, son)的体积
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[son][k] + w[i]); 
    }

    //循环中已经枚举了体积的所有情况，故不用再收尾
}


 
int main() {
    cin >> n >> m;
    
    memset(h, -1, sizeof h);    //初始化h数组
    
    for (int i = 0; i < n - 1; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    dfs(1, -1);     //-1表示1号点根节点不存在
    
    cout << f[1][m] << endl;
    
    return 0;
}