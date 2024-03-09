#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <conio.h>
#include <vector>
#include <queue>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
const int maxn = 5e3+10;
const int maxm = 5e5+10;
const int mod = 80112002;
// -----------------------DFS&递推__开始--------------------------------
struct rel{
    int a, b, next_a_peer;  //a被b捕食，next_a_peer记录下一个被b捕食的生物的捕食关系的位置
} ab[maxm];     //捕食关系表
int in[maxn], out[maxn];    //in[i]代表第i种生物的捕食的种类数目（入度），out[i]表示第i种生物的捕食者数目（出度）
int rel_index[maxn];    //rel_index[i]表示第i种生物作为捕食者所捕食的所有食物的入口
int dfs[maxn] = {0};
int n, m;
int x, y;   //x被y捕食
int res = 0;

int DFS(int i) {
    if (dfs[i]) return dfs[i];   //返回记忆化结果
    if (!in[i]) return 1;   //此时i为最底层生产者，找到一条最大化食物链，返回1。

    int temp = 0;
    for (int k=rel_index[i]; k; k=ab[k].next_a_peer) {
         temp = (temp + DFS(ab[k].a)) % mod;
    }
    dfs[i] = temp;
    return temp;
}

int main(void) {
    cin >> n >> m;
    fp(i, 1, m) {
        cin >> x >> y;
        ab[i].a = x;    //更新被捕食者
        ab[i].b = y;    //更新捕食者
        //存储下所有b作为捕食者的捕食关系，并通过next_a_peer形成一个链表，以便进行DFS
        ab[i].next_a_peer = rel_index[y];   
        rel_index[y] = i;   //更新捕食关系位置
        ++out[x]; ++in[y];  //更新相应的出度与入度
    }

    fp(i, 1, n) {
        if (!out[i]) {
            res = (res + DFS(i)) % mod;
        }
    }
    cout << res;

    _getch();
    return 0;
}

// -----------------------DFS&递推__结束--------------------------------

// ---------------------------拓扑排序BFS__开始------------------------------------
// vector<int> node[maxn];     //存储每种生物的捕食者
// queue<int> q;       //topo排序所用的queue
// int n, m;       
// int in[maxn], out[maxn];    //in[i]代表第i个结点的入度，out[i]代表第i个结点的出度。
// int num[maxn];  //存储到第i个结点的路径数量
// int res = 0;
// int x, y;   //输入捕食关系，x->y。


// int main(void) {
//     cin >> n >> m;
//     fp(i, 1, m) {
//         cin >> x >> y;
//         node[x].push_back(y);   //存储x的捕食者
//         // 更新与x, y结点相对应的出度与入度
//         ++out[x];   
//         ++in[y];
//     }

//     fp(i, 1, n) {
//         if (in[i] == 0) {
//             num[i] = 1; //设定初始结点的路径数量
//             q.push(i);  //初始将所有入度为0（最底层生产者）加入topo队列
//         }
//     }
    
//     // Topo排序，BFS搜索
//     while (!q.empty()) {
//         int top = q.front();    //取出队首元素
//         q.pop();    //弹出队首元素
//         //找出top结点的捕食者们
//         for (int i=0; i<int(node[top].size()); i++) {
//             --in[node[top][i]]; //入度减1
//             if(in[node[top][i]] == 0) q.push(node[top][i]);     //当入度为0时，将对应的捕食者加入topo队列中
//             num[node[top][i]] =  (num[node[top][i]] + num[top]) % mod;  //更新路径数量, 注意需要求余
//         }
//     }

//     fp(i, 1, n) {
//         if (out[i]==0) {
//             //cout << num[i] << " ";
//             res = (res + num[i]) % mod;
//         }
//     }
//     cout << res;

//     _getch();
//     return 0;
// }

// ---------------------------拓扑排序BFS__结束------------------------------------
