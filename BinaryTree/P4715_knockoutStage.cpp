#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 300;
const int max4n = 1200; //线段树数组大小开二叉树结点数量的四倍
struct node{
    int power, id;  //power代表该国家的能力值，id代表该国家的序号    
} cou[maxn];     
int stree[max4n] = {0}; //线段树数组

int build(int l, int r, int st) {
    if (l==r) {
        stree[st] = cou[l].power;
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, st<<1);       //build(l, mid, st*2)
    build(mid+1, r, st<<1|1);   //build(mid+1, r, st*2+1)
    stree[st] = stree[st<<1] + stree[st<<1|1];  //更新线段树结点值。
}

int main(void) {
    

    _getch();
    return 0;
}