//参考文献：https://blog.csdn.net/zearot/article/details/52280189
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(l); i--)
typedef long long ll;

using namespace std;
//------------------------线段树基本模板：建树，点修改，区间查询__开始----------------------------
const int maxn = 1e3+5;
int seq[maxn];  //待建树的序列，作为线段树stree的叶节点被存储起来
int stree[4*maxn];  //线段树，容量为seq的4倍（最低为大于seq容量的最小的2的幂的两倍）
int n;

//更新线段树结点的函数
void update(int loc) {
    //stree[loc] = stree[2*loc] + stree[2*loc+1]
    stree[loc] = stree[loc<<1] + stree[loc<<1|1];  
}

//建树函数
void build(int l, int r, int loc) { //[l, r]为待分割区间，loc为当前位置
    if (l==r) { //[l,r]只包含一个元素，不能继续分割，即已经到达叶节点位置，给stree[loc]赋值为seq[l]
        stree[loc] = seq[l];
        return;
    }
    int mid = (l+r)>>1; //将区间[l,r]对半分，实际上[l,mid].size>=[mid+1,r].size
    int leftchild = loc<<1;
    int rightchild = loc<<1|1;
    build(l, mid, leftchild);   //构建左子树
    build(mid+1, r, rightchild);    //构建右子树
    update(loc);    //更新当前结点的值，模板为其左右子结点的和，可以根据实际情况修改更新函数
}  

//点修改，假定操作为seq[L]+=C
void nodeUpdate(int L, int C, int l, int r, int loc) {  //[l, r]为待分割区间，loc为当前位置
    if (l==r) {  //到达叶节点，且由于搜索规则，到达的叶结点即为seq[L]
        stree[loc]+=C;
        return;
    }
    int mid = (l+r)>>1;
    int leftchild = loc<<1;
    int rightchild = loc<<1|1;
    if (L<=mid) nodeUpdate(L, C, l, mid, leftchild);    //seq[L]在左子树中
    else nodeUpdate(L, C, mid+1, r, rightchild);    //seq[L]在右子树中
    update(loc);    //更新当前节点的值
}

//区间查询，假定操作为求区间seq[L-R]的和
int intervalQuery(int L, int R, int l, int r, int loc) { //[l, r]为待分割区间，loc为当前位置
    if (L<=l && r<=R) {     //区间[l,r]在代求区间[L,R]内部，直接返回stree[l,r]的值
        return stree[loc];
    }
    int ans = 0;
    int mid = (l+r)>>1;
    int leftchild = loc<<1;
    int rightchild = loc<<1|1;
    if (L <= mid) ans += intervalQuery(L, R, l, mid, leftchild);    //如果[L,R]与[l,r]分割后的左区间有重叠，则继续搜索左子树
    if (R >= mid+1) ans += intervalQuery(L, R, mid+1, r, rightchild);   //如果[L,R]与[l,r]分割后的右区间有重叠，则继续搜索右子树
    return ans; //递归返回结果
}
//------------------------线段树基本模板：建树，点修改，区间查询__结束----------------------------

int main(void){
    cin >> n;
    fp(i, 1, 1<<n) cin >> seq[i];
    build(1, 1<<n, 1);  //线段树建树，注意线段树建树时，根节点从1开始，
                        //则对于结点n，其左子树的结点为2n， 右子树结点为2n+1
    nodeUpdate(1, 3, 1, 1<<n, 1);   //seq[1]+=3;
    int sum = intervalQuery(2, 6, 1, 1<<n, 1);  //求seq[2-6]的和
    cout << sum;

    _getch();
    return 0;
}


