// 图论基础知识(存图，最短路算法)与模板
// Reference: 
//   https://zhuanlan.zhihu.com/p/94890350
//   https://zhuanlan.zhihu.com/p/96621396
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
const int maxn = 1005;      //图中结点数
const int maxm = 1e5+5;     //图中边的数目

//一.存图方法
//------------------------------------邻接矩阵__开始—-------------------------------------------
int mat[maxn][maxn];    //邻接矩阵
//邻接矩阵，示例：双向有边权图
inline void add1(int u, int v, int w) {
    mat[u][v] = w;
    mat[v][u] = w;
}
//------------------------------------邻接矩阵__结束—-------------------------------------------

//------------------------------------邻接表__开始--------------------------------------------
// 邻接表：链表数组实现，将邻接矩阵的行从数组替换为链表
// 我们需要用一个边的结构体来同时储存边的终点（相当于邻接矩阵的第二个下标）和权值

//如果没有边权可以不使用结构体，只存储终点即可
struct edge {
    int to, w;  //to代表边的终点，w代表该边的权值
};
// 使用STL中vector实现类链表数组
vector<edge> nodes[maxn];   //nodes[i]存储了i结点所有的邻边与邻接结点
inline void add2(int from, int to, int w) {
    edge e = {to, w};
    nodes[from].push_back(e);   //将相邻边与相邻结点信息存入动态数组中
}
// 存储图，对于无向图，调用两次add()
inline void add3(int u, int v, int w) {
    add2(u, v, w);
    add2(v, u, w);
}

// 遍历所有结点方法
inline void traverse(void) {
    for (int i=0; i<int(nodes[2].size()); i++) {
        cout << nodes[2][i].to << " ";  //打印2号结点所有的邻接结点
    }
    //range-based for形式
    for (auto &no: nodes[2]) {
        cout << no.to << " ";
    }
}

//------------------------------------邻接表__结束--------------------------------------------

//---------------------------链式前向星__开始---------------------------------------------
struct edge2 {
    int to, w, next;    //to,w意义参考邻接表实现方法，next存储下一个结点（实际为前向结点）索引位置
} edges[maxm];
int head[maxn] = {0};   //head[i]为第i个结点的相邻结点形成的链表的头节点
int cnt=0;    //edges[maxn]结构体数组计数器

// 更新插入函数
inline void add4(int from, int to, int w) {
    edges[++cnt].to = to;
    edges[cnt].w = w;
    edges[cnt].next = head[from];   //存储上一次存入的前向结点，结束终点为0
    head[from] = cnt;   //记录当前邻边和相邻结点在edges[maxm]数组中的位置
}

// 遍历函数，例子：打印2号结点所有的邻接结点
inline void traverse2(void) {
    for (int e=head[2]; e!=0; e=edges[e].next) {
        cout << edges[e].to << " " << endl;
    }
} 

//---------------------------链式前向星__结束---------------------------------------------

//二.最短路径算法




int main(void) {

    _getch();
    return 0;
}