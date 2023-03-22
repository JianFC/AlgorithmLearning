// P3379 【模板】最近公共祖先（LCA）

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 5e5+5;
struct edge {
    int from, to, next;
}edges[2*maxn];
int head[maxn], cnt=0;
int fa[maxn][20], depth[maxn];  //fa[i][j]表示第i个结点的2^j个祖先
int n, m, s;    //意义参见题目

//链式前向星存图
inline void add(int from, int to) {
    edges[++cnt].to = to; 
    edges[cnt].from = from;
    edges[cnt].next = head[from];
    head[from] = cnt;
}

//深搜遍历树并初始化fa与depth数组
inline void dfs(int root, int pre) {
    fa[root][0] = pre; depth[root] = depth[pre]+1;
    for (int i=1; (1<<i)<=depth[root]; i++) {
        //状态转移方程，root的第2^i个祖先等于root的第2^(i-1)个祖先的第2^(i-1)个祖先
        fa[root][i] = fa[fa[root][i-1]][i-1];   
    }

    for (int i=head[root]; i; i=edges[i].next) {
        if (edges[i].to != pre) {     //消除无向图双向边的影响
            dfs(edges[i].to, root);   //继续深搜
        }
    }
}

//查询LCA（Least Common Ancestors）函数，查询结点a，b的最近公共祖先
inline int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);    //使a所代表结点的深度始终大于b所代表结点的深度

    //运用倍增使a跳到与b同一深度
    for (int i=19; i>=0; i--) {
        if (depth[a] - (1<<i) >= depth[b]) {
            a = fa[a][i];
            if (depth[a] == depth[b]) break;
        }
    }
    
    if (a==b) return a;
    
    //a与b同时向上跳，从大到小遍历步长，若fa[a][i]==fa[b][i]则不跳，fa[a][i]!=fa[b][i]则跳上去，向下贪心
    for (int i=19; i>=0; i--) {
        if (fa[a][i] != fa[b][i]) {
            a = fa[a][i];
            b = fa[b][i];
        }
    }

    //最后fa[a][0](=fa[b][0]),即为a与b的LCA
    return fa[a][0];
}

int main(void) {
    cin >> n >> m >> s;
    int x, y;
    fp(i, 1, n-1) {
        cin >> x >> y;
        add(x, y); add(y, x);   //无向图
    }
    //深搜图
    dfs(s, 0);
    
    //输出结果
    int a, b;
    fp(i, 1, m) {
        cin >> a >> b;
        cout << LCA(a, b) << endl;
    }

    _getch();
    return 0;
}