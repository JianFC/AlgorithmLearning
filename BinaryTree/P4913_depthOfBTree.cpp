//考察二叉树的存储，主要使用结构体来进行存储。
#include <iostream>
#include <algorithm>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
const int maxn = 1e6+5;
struct node {
    int left, right;    //tree[i].left代表第i个结点的左结点, tree[i].right代表第i个结点的右结点
} tree[maxn];   //二叉树的常见存储方式：定义包含左右结点的结构体
int n;
int res = 0; 

//深搜
void DFS(int id, int deepth) {
    if (id == 0) return;    //递归上一层结点是叶子结点，返回，深度不变
    res = max(res, deepth); //每到达一层则更新当前的最深深度
    DFS(tree[id].left, deepth+1);   //遍历左子树
    DFS(tree[id].right, deepth+1);  ///遍历右子树
}

int main(void) {
    cin >> n;
    fp(i, 1, n) cin >> tree[i].left >> tree[i].right;
    DFS(1, 1);
    cout << res;

    _getch();
    return 0;
}

