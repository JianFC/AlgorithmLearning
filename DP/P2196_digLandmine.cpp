#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
// -------------------方法2：DFS搜索__开始---------------------------------
const int maxn = 50;
int map[maxn][maxn] = {0};  //可达性矩阵
int a[maxn];        //第i个地窖地雷个数
int dfs[maxn];      //到第i个地窖最多可获得地雷数组
int path[maxn];     //保存路径，使用前驱结点进行递推
int n;
int res = 0;
int pos = 0;

// 深搜每个结点最大地雷数
int DFS(int i) {
    if (dfs[i]) return dfs[i];
    int temp = 0;
    fp(k, 1, i-1) {   
        if(map[k][i]) {
            temp = DFS(k);
            if (temp > dfs[i]) {
                dfs[i] = temp;
                path[i] = k;
            }
        }
    }
    dfs[i] += a[i];
    return dfs[i];
}

//递推输出路径
void printPath(int x) { 
    if(path[x]) printPath(path[x]);
    cout << x << " ";
}

int main(void) {
    cin >> n;
    fp(i, 1, n) cin >> a[i];
    fp(i, 1, n-1) {
        //注意此处输入的格式，列对齐
        fp(j, i+1, n) {
            cin >> map[i][j];   
        }
    }

    fp(i, 1, n) {
        DFS(i);
        if (dfs[i] > res) {
            res = dfs[i]; 
            pos = i;
        }
        //cout << dfs[i] << " ";
    }

    printPath(pos);
    cout << endl << res;

    _getch();
    return 0;
}

// -------------------方法2：DFS搜索__结束---------------------------------


// --------------------------DP__开始----------------------------------------
// const int maxn = 50;
// int map[maxn][maxn] = {0};  //可达性矩阵
// int a[maxn] = {0};      //a[i]表示第i个地窖的地雷个数
// int dp[maxn] = {0};
// int path[maxn] = {0};   //经过地窖的顺序, path[i]表示第i个地窖的前驱地窖。
// int n;
// int res = 0;
// int pos = 0;    //有最多地雷路径的终点地窖位置

// // 利用前驱结点信息，通过dfs输出最长路径
// void DFS(int x) {
//     if(path[x]) DFS(path[x]);   //找到前驱节点，DFS递归搜索
//     cout << x << " ";
// }

// int main(void) {
//     cin >> n;
//     fp(i, 1, n) cin >> a[i];
//     fp(i, 1, n-1) {
//         //注意此处输入的格式，列对齐
//         fp(j, i+1, n) {
//             cin >> map[i][j];   
//         }
//     }

//     fp(i, 1, n) {
//         fp(j, 1, i-1) {
//             if(map[j][i] && dp[j]>dp[i]) {
//                 dp[i] = dp[j];
//                 path[i] = j;    //第i个地窖的前驱是第j个地窖
//             }
//         }
//         dp[i] += a[i];
//         if (dp[i] > res) {
//             res = dp[i];
//             pos = i;
//         }
//         //cout << dp[i] << " ";
//     }

//     DFS(pos);
//     cout << endl << res;

//     _getch();
//     return 0;
// }
// --------------------------DP__结束----------------------------------------
