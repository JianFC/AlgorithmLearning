//树状数组模板

//树状数组与线段树比较
// 1.两者在复杂度上同级, 但是树状数组的常数明显优于线段树, 其编程复杂度也远小于线段树.
// 2.树状数组的作用被线段树完全涵盖, 凡是可以使用树状数组解决的问题, 使用线段树一定可以解决, 但是线段树能够解决的问题树状数组未必能够解决.
// 3.树状数组的突出特点是其编程的极端简洁性, 使用lowbit技术可以在很短的几步操作中完成树状数组的核心操作，其代码效率远高于线段树。

//References： 
//    1. https://blog.csdn.net/bestsort/article/details/80796531
//    2. https://zhuanlan.zhihu.com/p/93795692
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(l); i--)
#define lowbit(x) (x)&(-x)
typedef long long ll;

using namespace std;
const int maxn = 1e5+5;
int tree[maxn];     

//更新结点：原序列A[i]+=x;
inline void update(int i, int x) {
    for (int pos = i; pos<=maxn; pos+=lowbit(pos)) {
        tree[pos] += x;
    }
}

//求原序列A[i]前n项和
inline int query(int n) {
    int ans = 0;
    for (int pos=n; pos; pos-=lowbit(pos)) {
        ans += tree[pos];
    }
    return ans;
}

//区间查询：求A[i..j]的和
inline int query(int i, int j) {
    return query(j)-query(i-1);
}




