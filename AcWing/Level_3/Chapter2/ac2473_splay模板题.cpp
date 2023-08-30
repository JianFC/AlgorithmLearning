#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
struct Node {
    //s[0], s[1]分别代表左右儿子，p代表父结点，v代表当前结点存储的值
    //只有插入时满足BST的性质，后续操作可能不满足BST定义
    int s[2], p, v;     
    //size维护当前结点左右儿子+当前结点所有个数信息
    //flag维护懒标记，表示当前结点是否需要翻转
    int size, flag;     
    
    void init(int _v, int _p) {     //插入结点时初始化函数
        v = _v, p = _p;
        size = 1;
    }
    
}tr[N];

int root, idx;  //root根节点，idx表示当前使用到了哪个结点

void pushup(int x) {    //信息向上传递，更新size，每次旋转最后
    tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + 1; //左右儿子+1
}

void pushdown(int x) {  //将懒标记flag下传，向下传递，每次递归操作之前
    if (tr[x].flag) {   //当前结点需要翻转
        swap(tr[x].s[0], tr[x].s[1]);   //注意是交换x的左右两颗子树位置
        tr[tr[x].s[0]].flag ^= 1;   //和1异或，1->0, 0->1，即下传子树懒标记
        tr[tr[x].s[1]].flag ^= 1;
        tr[x].flag = 0;     //重置当前结点懒标记
    }
}

void rotate(int x) {    //将x（右儿子）左旋或者（左儿子）右旋到其父结点位置
    int y = tr[x].p, z = tr[y].p;   //y是x父结点，z是y父结点
    //k=0表示x是y左儿子，1表示x是y右儿子，根据k动态实现左旋或者右旋
    int k = tr[y].s[1] == x;
    //将x左右旋一共需要变三条边
    //1. 将x转到原y的位置
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;  //t[z].s[1]==y即为x该放的位置
    //2. 将x的右或者左儿子变为现y的儿子，根据左右旋图理解
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    //3. 将现y变为x的儿子，据图理解
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    
    //旋转之后pushup操作，信息从下往上传递
    pushup(y), pushup(x);   //注意顺序
}

void splay(int x, int k) {  //splay核心函数，将点x旋转至k下面
    while (tr[x].p != k) {  //x还未旋转至k下面
        int y = tr[x].p, z = tr[y].p;   //y是x父，z是y父
        if (z != k) {   //需要转两次
            //判断结果0表示直线型，1表示折线型
            if ((tr[z].s[1] == y) ^ (tr[y].s[1] == x)) rotate(x);  //折线先转x
            else rotate(y);     //直线型先转y
        }
        rotate(x);  //再旋转一次x
    }
    
    if (!k) root = x;   //splay(x, 0)表示将x旋转为根节点，更新根节点
}

void insert(int v) {    //在splay中新插一个结点v，插入和旋转时满足BST性质
                        //根据题意，insert时无需下传懒标记
    int u = root, p = 0;    //从根节点开始往下迭代，p表示u的父结点  
    while (u) p = u, u = tr[u].s[v > tr[u].v];  //更新p，根据v更新u
    u = ++ idx;  //idx自增
    if (p) tr[p].s[v > tr[p].v] = u;    //如果u存在父结点，更新父结点儿子信息
    tr[u].init(v, p);   //更新新增u结点的v和p信息
    splay(u, 0);    //根据splay定义将新增点旋至根节点
}

int get_k(int k) {  //获取中序遍历中第k个点
    int u = root;   //从根节点开始，迭代法获取
    while (u) {
        pushdown(u);    //递归之前下传懒标记
        if (tr[tr[u].s[0]].size >= k) u = tr[u].s[0];   //左子树中找
        else if (tr[tr[u].s[0]].size + 1 == k) return u; //将该点索引返回
        else k -= tr[tr[u].s[0]].size + 1, u = tr[u].s[1];     //更新k，右子树中找
    }
    
    return -1;  //没有找到第k个点
}

void output(int u) {     //递归输出u结点子树中序遍历结果，即我们需要维护的序列
    pushdown(u);    //递归之前下放懒标记
    if (tr[u].s[0]) output(tr[u].s[0]);     //递归左子树
    //如果不是左右哨兵，则输出
    if (tr[u].v > 0 && tr[u].v < n + 1) printf("%d ", tr[u].v);   
    if (tr[u].s[1]) output(tr[u].s[1]);     //递归右子树
}

int main(void) {
    scanf("%d%d", &n, &m);
    
    //按序插入n个结点，并在左右分别插入两个哨兵结点（0和n+1类似treap）
    for (int i = 0; i <= n + 1; i++) insert(i);
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        l = get_k(l), r= get_k(r + 2);    //考虑哨兵，[l, r]的前驱后继分别为l和r+2 
        //将L+1前驱L旋转至root，R+1后继R+2旋转至L，则[L+1, R+1]位于R+2左子树中
        //进一步将R+2左子树懒标记^1(1->0, 0->1)，实现原序列[L, R]的翻转。
        splay(l, 0), splay(r, l);
        tr[tr[r].s[0]].flag ^= 1;     //设置懒标记，实现序列翻转
    }
    
    output(root);   //输出最终序列
    
    return 0;
}