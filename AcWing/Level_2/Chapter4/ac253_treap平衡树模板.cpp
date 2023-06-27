#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;        //253. 普通平衡树

const int N = 100010, INF = 1e8;

int n;
struct Node {
    int l, r;   //l，r分别表示左右儿子的编号
    int key, val;   //key表示BST排序的权值，val表示大根堆的权值
    int cnt, size;  //cnt表示当前结点出现的次数，size表示左右子树和当前结点cnt之和，用于求排名rank
}tr[N];

int root, idx;  //root表示根结点，idx表示当前使用到了第几个结点，和链表中idx同义

void pushup(int p) {    //利用p的左右儿子信息维护p的信息，信息往上传递
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

int get_node(int key) {     //创建一个结点
    tr[++idx].key = key;
    tr[idx].val = rand();    //创建结点时，随机赋value值
    tr[idx].cnt = tr[idx].size = 1;     //创建结点时，为叶结点, cnt = size = 1
    return idx;     //返回创建节点的编号
}

void zig(int &p) {      //对结点p右旋，需要更改实参的值，故传引用
    int q = tr[p].l;    //旋转后p的左儿子q将成为父结点
    tr[p].l = tr[q].r, tr[q].r = p, p = q;  //p左结点=q右节点，q右节点=p，q成为新父结点
    pushup(tr[p].r), pushup(p);     //更新原父结点与新父结点的信息，注意顺序从下往上
    
}

void zag(int &p) {  //对结点p左旋
    int q = tr[p].r;
    tr[p].r = tr[q].l, tr[q].l = p, p = q;  //对称，p右节点=q左结点，q左结点=p，q成为新父结点
    pushup(tr[p].l), pushup(p);
}

void build() {  //初始化树
    get_node(-INF), get_node(INF);  //创建两个哨兵结点(1, 2)，简化边界判断，0表示空结点
    root = 1, tr[root].r = 2;   //初始化树结构，-INF为根结点，INF为右儿子
    pushup(root);   //更新root结点信息
    
    if (tr[1].val < tr[2].val) zag(root);   //满足大根堆
}

void insert(int &p, int key) {  //插入一个key，需要更改实参的值，故传引用，递归实现
    if (!p) p = get_node(key);  //到达空叶子位置，新建一个叶子结点，记得更新p
    else if (tr[p].key == key) tr[p].cnt++;     //当前结点key==插入key，cnt++
    else if (tr[p].key > key) {
        insert(tr[p].l, key);   //在左子树中去插入key
        if (tr[tr[p].l].val > tr[p].val) zig(p);    //插入后如果左子树val>父val，右旋父结点
    }
    else {
        insert(tr[p].r, key);   //对称，左子树中去插入key
        if (tr[tr[p].r].val > tr[p].val) zag(p);    //右子树val>父val，左旋父结点
    }
    
    pushup(p);  //从下往上更新p结点信息
}

void remove(int &p, int key) {  //删除一个key，需要更改实参的值，故传引用，递归实现
    if (!p) return;     //删除的key不存在，直接return
    if (tr[p].key == key) {
        if (tr[p].cnt > 1) tr[p].cnt--;     //当前结点个数>1, cnt--;
        else if (tr[p].l || tr[p].r) {      //当前结点存在左子树或右子树
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) {
                //当前结点右子树不存在 || 左儿子val > 右儿子val -> 右旋
                zig(p);     //右旋，右旋后原p结点 = 新p结点.r
                remove(tr[p].r, key);   //将原p结点递归旋转至叶子结点，并删除
            }
            else {  //否则左旋
                zag(p);     //左旋
                remove(tr[p].l, key);
            }
        }
        else p = 0;     //已经旋转至叶子结点，令p=0直接删除
    }
    else if (tr[p].key > key) remove(tr[p].l, key);     //去左子树中删
    else remove(tr[p].r, key);      //去右子树中删
    
    pushup(p);      //从下往上更新p结点信息
}

int get_rank_by_key(int p, int key) {   //根据key找排名，不涉及修改操作，不用传引用
    if (!p) return 0;   //所找key不存在，返回rank=0，本题中不存在此情况
    if (tr[p].key == key) return tr[tr[p].l].size + 1;    //左子树size+1，即为rank
    if (tr[p].key > key) return get_rank_by_key(tr[p].l, key);     //左子树中找
    return tr[tr[p].l].size + tr[p].cnt + get_rank_by_key(tr[p].r, key);    //左子树size+父结点cnt+右子树中找
}

int get_key_by_rank(int p, int rank) {  //通过rank找key
    if (!p) return INF;     //所找rank不存在，返回key=INF，本题中不存在此情况
    if (tr[tr[p].l].size >= rank) return get_key_by_rank(tr[p].l, rank);     //左子树中找，注意>=
    if (tr[tr[p].l].size + tr[p].cnt >= rank) return tr[p].key;     //此时p.key即为所找
    return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt);   //右子树中找，记得更新rank
}

int get_prev(int p, int key) {  //找前驱，严格小于key的最大数
    if (!p) return -INF;
    if (tr[p].key >= key) return get_prev(tr[p].l, key);    //左子树中找
    return max(tr[p].key, get_prev(tr[p].r, key));  //注意需加上max，因为递归终点可能返回-INF
}

int get_next(int p, int key) {  //找后继，严格大于key的最小数
    if (!p) return INF;
    if (tr[p].key <= key) return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));  
}

int main(void) {
    build();
    
    scanf("%d", &n);
    while (n--) {
        int opt, x;
        scanf("%d%d", &opt, &x);
        
        if (opt == 1) insert(root, x);
        else if (opt == 2) remove(root, x);
        else if (opt == 3) printf("%d\n", get_rank_by_key(root, x) - 1);    //-1考虑左哨兵
        else if (opt == 4) printf("%d\n", get_key_by_rank(root, x + 1));   //+1考虑左哨兵
        else if (opt == 5) printf("%d\n", get_prev(root, x));
        else printf("%d\n", get_next(root, x));
    }
    
    return 0;
}