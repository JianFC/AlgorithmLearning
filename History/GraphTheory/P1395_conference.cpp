//P1395 会议

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 5e4+10;
struct edges {
    int from, to, next;
} edges[maxn<<1];
int head[maxn], cnt = 0;
int siz[maxn] = {0};     //siz[i]表示第i个结点加上其子树结点的数量
int dp[maxn] = {0};   //dp[i]表示将第i个结点选为会议地点时的距离总和
int n;  //结点总数
int pos, res = 0x7fffffff;  //pos表示结果结点所在的位置，res表示其距离总和

//链式前向星存图
inline void add(int from, int to) {
    edges[++cnt].to = to;
    edges[cnt].from = from;
    edges[cnt].next = head[from];
    head[from] = cnt;
}

// 假定1号结点为树的根，求出dp[1]和每个size[i]
// root表示当前结点，pre表示root的父结点，dep表示当前所处树的深度-1
inline void dfs1(int root, int pre, int dep) {  
    siz[root] = 1;  dp[1]+=dep;
    for (int e = head[root]; e; e=edges[e].next) {  //注意 e= edges[e].next!!!
        if (edges[e].to == pre) continue;   //不能往父亲方向走，保证单次遍历与深度不断递增
        dfs1(edges[e].to, root, dep+1);
        siz[root] += siz[edges[e].to];  //更新siz[root]的值
    }
}

// 树上dp，求出所有点的距离总和
// 设i为j的父结点，则状态转移方程dp[j] = dp[i] + (n-siz[j]) - siz[j];
// 假设1号结点为树的根节点，从1号结点开始深搜
inline void dfs2(int root, int pre) {
    for (int e = head[root]; e; e = edges[e].next) {
        if (edges[e].to == pre) continue;
        dp[edges[e].to] = dp[root] + (n-siz[edges[e].to]) - siz[edges[e].to]; //状态转移方程，注意状态转移方程的位置！
        dfs2(edges[e].to, root);
    }
}

int main(void) {
    cin >> n;   //注意细节，n定义为全局变量
    int a, b; 
    fp(i, 1, n-1) {
        cin >> a >> b;
        add(a, b); add(b, a);   //存储无向图
    }

    dfs1(1, 0, 0); dfs2(1, 0);
    
    fp(i, 1, n) {
        if (dp[i] < res) { res = dp[i]; pos = i; }
    }
    cout << pos << " " << res;

    _getch();
    return 0;
}