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
//-----------------------------------------线段树__开始--------------------------------
// const int maxn = 300;
// const int max4n = 1200; //线段树数组大小开二叉树结点数量的四倍
// struct node{
//     int power, id;  //power代表该国家的能力值，id代表该国家的序号    
// } cou[maxn], stree[max4n];     //stree线段树数组
// int n;

// node maxi(node a, node b) {
//     if (a.power > b.power) return a;
//     else return b;
// }

// node mini(node a, node b) {
//     if (a.power < b.power) return a;
//     else return b;
// }

// //线段树建树
// void build(int l, int r, int st) {
//     if (l==r) {
//         stree[st].power = cou[l].power;
//         stree[st].id = cou[l].id;
//         return;
//     }
//     int mid = (l+r)/2;
//     build(l, mid, st<<1);       //build(l, mid, st*2)
//     build(mid+1, r, st<<1|1);   //build(mid+1, r, st*2+1)
//     stree[st] = maxi(stree[st<<1], stree[st<<1|1]); 
// }

// int main(void) {
//     cin >> n;
//     fp(i, 1, 1<<n) {
//         cin >> cou[i].power;
//         cou[i].id = i;
//     }

//     build(1, 1<<n, 1);      //线段树建树，注意线段树建树时，根节点从1开始，
//                             //则对于结点n，其左子树的结点为2n， 右子树结点为2n+1
//     node ans = mini(stree[2], stree[3]);
//     cout << ans.id;

//     _getch();
//     return 0;
// }
//-----------------------------------------线段树__结束--------------------------------