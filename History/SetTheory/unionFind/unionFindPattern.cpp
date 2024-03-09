// 并查集
// references: https://zhuanlan.zhihu.com/p/93647900
#include <iostream>
#include <algorithm>
#include <conio.h>

using namespace std;
const int maxn = 1e5+5;
int fa[maxn] = {0}; //存储每个结点的父节点
int Rank[maxn] = {0};   //存储每个结点的秩，秩定义为每个根节点对应的树的深度
                        //（如果不是根节点，其Rank相当于以它作为根节点的子树的深度）

//初始化
inline void init(int n) {
    for (int i=1; i<=n; i++) {
        fa[i] = i;  //初始时每个结点的父节点均为自己
    }
}

//查询1：最简单版本
inline int find(int x) {
    if (fa[x] == x) {   //已经找到根节点
        return x;
    }
    else {
        return find(fa[x]); //未找到根节点，继续搜索
    }
}

//合并1
inline void merge(int i, int j) {
    fa[find(i)] = find(j);  //将i的根节点的子树合并到j的根节点上。
}

//查询2：查询时进行路径压缩
inline int find2(int x) {
    if (fa[x] == x) return x;
    else {
        fa[x] = find2(fa[x]);
        return fa[x];  
    }
}

//查询3：简化版本
inline int find2_1(int x) {
    return fa[x] == x ? x : (fa[x] = find2(fa[x]));
}

// 进一步优化_按秩合并_初始化
inline void init2(int n) {
    for (int i=1; i<=n; i++) {
        fa[i] = i;
        Rank[i] = 1;
    }
}

//按秩合并_合并
inline void merge(int i, int j) {
    int x = find2(i); int y = find2(j);
    if (Rank[x] <= Rank[y]) 
        fa[x] = y;  //将秩小的树合并到秩大的树上，从而最小化合并后树的深度
    else 
        fa[y] = x;  //此时不用更新Rank[x],新合并来的y并未导致x的Rank增加
    
    //当x，y (x!=y)两个子树的Rank相等时，需要更新合并后子树的Rank值，可画图进行理解
    if (Rank[x] == Rank[y] && x != y) Rank[y]++;
}

