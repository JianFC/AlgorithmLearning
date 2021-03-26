// 并查集
// references: https://zhuanlan.zhihu.com/p/93647900
#include <iostream>
#include <algorithm>
#include <conio.h>

using namespace std;
const int maxn = 1e5+5;
int fa[maxn] = {0}; //存储每个结点的父节点

//初始化
inline void init(int n) {
    for (int i=1; i<=n; i++) {
        fa[i] = i;  //初始时每个结点的父节点均为自己
    }
}
