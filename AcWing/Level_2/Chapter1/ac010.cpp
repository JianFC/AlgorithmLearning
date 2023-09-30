#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //10. 有依赖的背包问题

const int N = 110;

int n, m;
int v[N], w[N];     //v[i], w[i]分别表示第i个物品的体积和价值
int h[N], e[N], ne[N], idx;     //用于存储树的邻接表
int f[N][N];    //f[u][j]表示所有从以u为根的子树中选，且总体积不超过j的方案的价值最大值

void add(int a, int b) {    //邻接表加边函数
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u) {
    for (int i = h[u]; ~i; i = ne[i]) { //遍历u的所有子树，即循环物品组，~i即i != -1
        int son = e[i];
        dfs(son);   //递归处理u的每个子树
        
        //分组背包问题
        for (int j = m - v[u]; j >= 0; j --) //循环体积，因为必须要选上根节点，所以-v[u]，从大到小循环，优化维度
            for (int k = 0; k <= j; k ++)   //循环决策，子树以使用体积为划分依据，看选哪一组
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);    //状态转移方程
    }
    
    //将物品u加入选择方案
    for (int i = m; i >= v[u]; i --) f[u][i] = f[u][i - v[u]] + w[u];
    for (int i = 0; i < v[u]; i ++) f[u][i] = 0;    //体积小于v[u]的状态结果为0
}

int main() {
    cin >> n >> m;
    
    memset(h, -1, sizeof h);    //h数组初始化
    int root;   //用于存储根节点的编号
    for (int i = 1; i <= n; i ++) {
        int p;
        cin >> v[i] >> w[i] >> p;
        if (p == -1) root = i;  //记录根节点
        else add(p, i);     //否则添加从p到i的边
    }
    
    dfs(root);  //从根节点开始递归处理
    
    cout << f[root][m] << endl;     //f[root][m]存储答案
    
    return 0;
}