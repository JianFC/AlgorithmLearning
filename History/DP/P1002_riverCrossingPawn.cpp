#include <iostream>
#include <cstdio>
#include <algorithm>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 50;
const int maxm = 50;

long long map[maxn][maxm];
bool flag[maxn][maxm];     //flag[i][j]为1时该点为马的控制点，对应map[i][j]为0，即通过该店的路径数为0；
//马的控制点,从dx[1],dy[1]开始计数
int dx[9] = {0, -2, -2, -1, -1, 1, 1, 2, 2};
int dy[9] = {0, -1, 1, -2, 2, -2, 2, -1, 1};
int n, m, xh, yh;   //(n, m)代表B点的坐标，(xh, yh)代表马的坐标
// int bias = 2;   //整体向右下偏移两个单位，防止计算马的控制点时数组越界
int n0 = 0, m0 = 0;   //(x0, y0)为初始点，即A点

int main(void) {
    cin >> n >> m >> xh >> yh;
    fp(i, 0, 8) {
        if (xh+dx[i]>=0 && xh+dx[i]<=n && yh+dy[i]>=0 && yh+dy[i]<=m)        
            flag[xh+dx[i]][yh+dy[i]] = 1;    //写入马的控制点
    }
    //初始化第一行第一列。
    fp(i, 0, n) {
        if(!flag[i][0]) map[i][0] = 1;
        else break; //当边界点为马的控制点时，该点之后点的路径数必为0！,所以此处需要break！
            
    }
    fp(i, 0, m) {
        if(!flag[0][i]) map[0][i] = 1;
        else break;   //当边界点为马的控制点时，该点之后点的路径数必为0！,所以此处需要break！
    }


    fp(i, 1, n) {
        fp(j, 1, m) {
            if (flag[i][j]) map[i][j]=0;
            else map[i][j] = map[i-1][j]+map[i][j-1];
        }
    }

    cout << map[n][m];

    _getch();
    return 0;
}

// --------------------------------DFS(TLE)__开始-------------------------------
// int map[maxn][maxm] = {0};    //存储地图，马的控制点为1，其余点为0
// //移动方向
// int dx[2] = {1, 0};
// int dy[2] = {0, 1};
// int n, m, x2, y2;   //(n, m)代表B点的坐标，(x1, y1)代表马的坐标
// int res = 0;
// int bias = 2;

// //检查是否到达马的控制点,为false代表遇到马的控制点
// // bool check(int x, int y) {
// //     if ((x==x2&&y==y2) || (x==x2-1&&y==y2-2) || (x==x2-2&&y==y2-1) || (x==x2-2&&y==y2+1) || (x==x2-1&&y==y2+2) ||
// //         (x==x2+1&&y==y2-2) || (x==x2+2&&y==y2-1) || (x==x2+1&&y==y2+2) || (x==x2+2&&y==y2+1))
// //         return false;
// //     else return true;
// // }

// void DFS(int x, int y) {
//     if (x==n&&y==m) res += 1;
//     for (int i=0; i<=1; i++) {
//         int tempx = x+dx[i];
//         int tempy = y+dy[i];
//         if (tempx >= 0+bias && tempx <=n && tempy>=0+bias && tempy <=m && map[tempx][tempy]==0) {
//             DFS(tempx, tempy);
//         }
//     }

// }

// int main(void) {
//     cin >> n >> m >> x2 >> y2;
//     n += bias; m += bias; x2+=bias; y2+=bias;
//     map[x2][y2] = map[x2-1][y2-2] = map[x2-1][y2+2] = map[x2-2][y2-1] = map[x2-2][y2+1] = 1;
//     map[x2+1][y2-2] = map[x2+1][y2+2] = map[x2+2][y2+1] = map[x2+2][y2-1] = 1;

//     DFS(0+bias, 0+bias);
//     cout << res;

//     _getch();
//     return 0;
// }
// --------------------------------DFS(TLE)__结束-------------------------------