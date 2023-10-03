#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1077. 皇宫看守

const int N = 1510, M = N, INF = 0x3f3f3f3f;

int n;
int h[N], e[M], w[N], ne[M], idx;   //w记录点的权重
int f[N][3];    //状态0代表被父节点看到的最小花费，1代表被子节点看到的最小花费，2代表i点放上警卫
bool st[N];     //找根节点

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u) {
    f[u][2] = w[u];     //更新f[u][2]
    
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        dfs(j);
        
        f[u][0] += min(f[j][1], f[j][2]);   //状态0更新方式
        f[u][2] += min(min(f[j][0], f[j][1]), f[j][2]);     //状态2更新方式，三数的min
    }
    
    f[u][1] = INF;  //初始化状态1
    for (int i = h[u]; ~i; i = ne[i]) {     //枚举看到u的点是哪个儿子节点
        int j = e[i];
        //f[u][0] - min(f[j][1], f[j][2])即为除掉j的其余项的1，2状态的最小值
        f[u][1] = min(f[u][1], f[j][2] + f[u][0] - min(f[j][1], f[j][2]));
    }
}

int main() {
    cin >> n;
    
    memset(h, -1, sizeof h);
    
    for (int i = 1; i <= n; i ++) {
        int id, cost, m;
        cin >> id >> cost >> m;
        w[id] = cost;   //记录cost花费
        while (m --) {
            int ver;
            cin >> ver;
            add(id, ver);   //加边
            st[ver] = true;
        }
    }
    
    int root = 1;       //结点编号从1开始
    while (st[root]) root ++;   //找根节点
    
    dfs(root);
    
    cout << min(f[root][1], f[root][2]) << endl;    //输出1，2状态的最小值，root没有状态0
    
    return 0;
}
