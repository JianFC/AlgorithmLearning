#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;        //323. 战略游戏

const int N = 1510, M = N;      //有向图

int n;
int h[N], e[M], ne[M], idx;
int f[N][2];    //f[i, j]表示所有在以i为根的子树中选，且点i状态是j(0 or 1)的方案的最小值
bool st[N];     //记录哪个点是根节点

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u) {
    f[u][0] = 0, f[u][1] = 1;   //初始化u点
    
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        dfs(j);
        
        f[u][0] += f[j][1];     //u不选，则其儿子必选
        f[u][1] += min(f[j][0], f[j][1]);   //u选，其儿子可选可不选
    }
}

int main() {
    while (scanf("%d", &n) != -1) {     //没有数据scanf则返回-1，scanf返回的是读入数据的个数
        memset(h, -1, sizeof h);    //清空邻接表
        idx = 0;
        memset(st, 0, sizeof st);   //清空st数组
        
        for (int i = 0; i < n; i ++) {      //注意读入格式
            int id, cnt;
            scanf("%d:(%d)", &id, &cnt);    //读入点id和cnt
            while (cnt --) {    
                int ver;
                scanf("%d", &ver);
                add(id, ver);    //加边，注意是id
                st[ver] = true;     //不是根节点
            }
        }
        
        int root = 0;
        while (st[root]) root ++;   //找到根节点
        
        dfs(root);  //从根节点开始DP过程
        
        printf("%d\n", min(f[root][0], f[root][1]));    //注意输出的是最小值
        
    }
    
    return 0;
}