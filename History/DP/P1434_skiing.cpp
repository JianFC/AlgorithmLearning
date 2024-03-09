#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
// ---------------------------------方法2：线性动态规划__开始----------------------------
struct node {
    int x, y, h;    //x横坐标，y纵坐标，h为该节点高度
} a[10010];
int dp[10010] = {0};
bool cmp(node a, node b) {return a.h>b.h;}  //规定sort函数对node结构体按照高度h从高到低排序
// 方向数组
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int r, c;
int res = 0;
int n = 0;

//检查两个a[i]与a[j]是否相邻
bool check(int i, int j) {
    fp(k, 0, 3) {
        if (a[i].x+dx[k]==a[j].x && a[i].y+dy[k]==a[j].y) return true;
    }
    return false;
}

int main(void) {
    cin >> r >> c;
    fp(i, 1, r) {
        fp(j, 1, c) {
            cin >> a[++n].h;
            a[n].x = i;
            a[n].y = j;
        }
    }
    sort(a+1, a+1+n, cmp);  //对a按h从高到低进行排序,
    fp(i, 1, n) {
        dp[i] = 1;
        fd(j, i-1, 1) {
            if (check(i, j) && a[j].h > a[i].h) {
                //状态转移方程
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        // cout << dp[i] << " ";
        res = max(dp[i], res);
    }
    cout << res;

    _getch();
    return 0;
}

// ---------------------------------方法2：线性动态规划__结束----------------------------



// ---------------------------------方法1：记忆化搜索&DFS__开始--------------------------
// const int maxn = 105;
// int map[maxn][maxn] = {0};
// int dfs[maxn][maxn] = {0};
// int dx[4] = {-1, 0, 0, 1};
// int dy[4] = {0, -1, 1, 0};
// int res = 0;
// int r, c;

// int DFS(int i, int j) {
//     if (dfs[i][j] != 0) return dfs[i][j];   //记忆并剪枝
//     int t = 1;
//     //DFS深度搜索，递归结束条件为map[i][j]上下左右四个方向的数值都大于map[i][j]。
//     fp(k,0,3) {
//         int x = i+dx[k];
//         int y = j+dy[k];
//         if (x>=1 && x<=r && y>=1 && y<=c && map[i][j]>map[x][y]) {
//             t = max(t, DFS(x, y)+1);
//         }
//     }
//     dfs[i][j] = t; 
//     return dfs[i][j];
// }

// int main(void) {
//     cin >> r >> c;
//     fp(i, 1, r) {
//         fp(j, 1, c) {
//             cin >> map[i][j];
//         }
//     }

//     fp(i, 1, r) {
//         fp(j, 1, c) {
//             DFS(i, j);
//         //    cout << dfs[i][j] << " ";
//             res = max(res, dfs[i][j]);
//         }
//         // cout << endl;
//     }

//     cout << res;

//     _getch();
//     return 0;
// }
// ---------------------------------方法1：记忆化搜索&DFS__结束--------------------------
