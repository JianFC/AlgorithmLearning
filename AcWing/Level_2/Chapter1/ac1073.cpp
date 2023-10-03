#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1073. 树的中心

const int N = 10010, M = N * 2, INF = 0x3f3f3f3f;     //无向图

int n;
int h[N], e[M], w[M], ne[M], idx;   //邻接表存图
int d1[N], d2[N], p1[N], p2[N], up[N];  //d1[i]表示i节点向下的最远距离，p1[i]存储i节点的最大路径从哪个儿子节点来
//d2[i]表示i节点向下的次元距离，p2[i]存储次大路径从哪个儿子来, up[i]表示i节点向上走的最远距离
bool is_leaf[N];    //判断节点是否为叶子节点

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

//子节点信息更新父节点信息
int dfs_d(int u, int father) {      //返回值为向下走的最远距离
    d1[u] = d2[u] = -INF;   //初始化d1[u]和d2[u]，
    
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;  //不能往回走
        int d = dfs_d(j, u) + w[i];   //每个节点向下走的最远距离
        
        if (d >= d1[u]) {
            d2[u] = d1[u], d1[u] = d;   //更新d数组
            p2[u] = p1[u], p1[u] = j;   //更新p数组，用子节点信息更新父节点信息
        }
        else if (d > d2[u]) {
            d2[u] = d, p2[u] = j;   //更新次远距离信息
        }
    }
    
    if (d1[u] == -INF) {
        d1[u] = d2[u] = 0;  //不能用h[u] == -1来判定，因为是无向图
        is_leaf[u] = true;  //该点为叶节点
    }
    
    return d1[u];   //返回向下走的最远距离
}

//父节点信息更新子节点信息
void dfs_u(int u, int father) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;  //跳过
        
        if (j == p1[u]) up[j] = max(up[u], d2[u]) + w[i];  //父节点信息更新子节点信息，且d1[u]经过j
        else up[j] = max(up[u], d1[u]) + w[i];             //d1[u]不经过j，用d1[u]和up[u]来更新
        
        dfs_u(j, u);      //递归向下求
    }
}

int main() {
    cin >> n;
    
    memset(h, -1, sizeof h);    //初始化
    
    for (int i = 0; i < n - 1; i ++) {  //读入n - 1条边
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);     //无向图
    }
    
    dfs_d(1, -1);   //假设1号点为根节点，第一遍dfs，求出d1, p1和d2, p2
    dfs_u(1, -1);   //第二遍dfs，求出up数组
    
    int res = INF;  //找出距离其他点的最远距离最近的点
    for (int i = 1; i <= n; i ++)
        if (is_leaf[i]) res = min(res, up[i]);  //叶子节点只能向上找最远距离
        else res = min(res, max(d1[i], up[i])); //对于点i，向上走和向下走的最远距离max即为到所有点的最远距离
    
    cout << res << endl;
    
    return 0;
}