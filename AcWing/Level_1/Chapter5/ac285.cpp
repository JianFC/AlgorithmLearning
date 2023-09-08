#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 6010, M = 6010;;

int n;
int happy[N];
int h[N], e[M], ne[M], idx;     //邻接表存图
bool has_fa[N];     //用于记录第i个结点是否有父结点，树根没有父结点
int f[N][2];//f[u][0]表示所有从以u为根的子树中选择的方案，且不选u的方案集合的最大h值
            //f[u][1]表示所有从以u为根的子树中选择的方案，且选u的方案集合的最大h值

void add(int a, int b) {        //AcWing 285. 没有上司的舞会
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    f[u][1] = happy[u]; //选择u，加上u的happy值

    //枚举u的所有儿子
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        dfs(j);     //递归搜索j的儿子

        //根据状态转移方程计算f[u][0]与f[u][1]
        f[u][0] += max(f[j][0], f[j][1]); 
        f[u][1] += f[j][0];
    }
}

int main(void) {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", &happy[i]);

    memset(h, -1, sizeof h);    //初始化链表头结点

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(b, a);  //新增一条b到a的边，表示b是a的上级
        has_fa[a] = true;   //a有父结点，不是根结点
    }

    int root = 1;
    while (has_fa[root]) root++;    //找出根结点

    dfs(root);  //从根结点递归往下搜索

    printf("%d\n", max(f[root][0], f[root][1]));    //校长参与or校长不参与

    return 0;
}