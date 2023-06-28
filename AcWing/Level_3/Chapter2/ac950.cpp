#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;        //950. 郁闷的出纳员

const int N = 100010, INF = 1e8;

int n, m, delta;    //m表示最低工资，splay中结点v+delta=实际工资
                    //整体加减工资在delta上操作
struct Node {
    int s[2], p, v;
    int size;
    
    void init(int _v, int _p) {
        v = _v, p = _p;
        size = 1;
    }
}tr[N];

int root, idx;

void pushup(int x) {
    tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + 1;
}

void rotate(int x) {
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    
    pushup(y), pushup(x);
}

void splay(int x, int k) {
    while (tr[x].p != k) {
        int y = tr[x].p, z = tr[y].p;
        if (z != k)
            if ((tr[z].s[1] == y) ^ (tr[y].s[1] == x)) rotate(x);
            else rotate(y);
        rotate(x);
    }
    
    if (!k) root = x;
}

int insert(int v) {
    int u = root, p = 0;
    while (u) p = u, u = tr[u].s[v > tr[u].v];
    u = ++ idx;
    if (p) tr[p].s[v > tr[p].v] = u;
    tr[u].init(v, p);
    splay(u, 0);    //旋转至根节点
    return u;   //需要用到左哨兵，故返回下标
}

int get_next(int v) {   //注意是找到v的后继，本题splay维护有序序列
    int u = root, res = 0;   //res存储后继下标，使用迭代方式
    while (u) {
        //注意是比较符号！
        if (tr[u].v >= v) res = u, u = tr[u].s[0];  //更新res，进入左子树
        else u = tr[u].s[1];    //进入右子树
    }
    
    return res;
}

int get_k(int k) {
    int u = root;
    while (u) {
        if (tr[tr[u].s[0]].size >= k) u = tr[u].s[0];
        else if (tr[tr[u].s[0]].size + 1 == k) return tr[u].v; //注意此时返回v！
        else k -= tr[tr[u].s[0]].size + 1, u = tr[u].s[1];
    }
    
    return -1;
}

int main(void) {
    scanf("%d%d", &n, &m);
    //插入两个哨兵结点，并记录下标，右哨兵未使用
    int L = insert(-INF), R = insert(INF);
    
    int tot = 0;    //加入过公司的总人数
    while (n--) {
        char op[2];
        int k;
        scanf("%s%d", op, &k);
        
        if (*op == 'I') {
            //保证结点.v+delta=实际工资
            if (k >= m) insert(k - delta), tot ++;  
        }
        else if (*op == 'A') delta += k;
        else if (*op == 'S') {
            delta -= k;
            R = get_next(m - delta);    //找到当前工资低于最低标准的右边界+1，即后继
            splay(R, 0), splay(L, R);   //splay操作后，L右子树需要删除的人
            tr[L].s[1] = 0;     //删除L右子树
            pushup(L), pushup(R);   //记得pushup操作！
        }
        else {
            if (k > tr[root].size - 2) puts("-1");
            else {
                //考虑右哨兵，第k大数为第size-k小数, 注意需要加上delta
                printf("%d\n", get_k(tr[root].size - k) + delta);
            }
        }
    }
    
    printf("%d\n", tot - (tr[root].size - 2));    //-2删除两哨兵
    
    return 0;
}

