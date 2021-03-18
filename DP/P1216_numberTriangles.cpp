#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
const int maxr = 1e3;

//全局变量不占用堆栈区，申请数组上界相较于栈（在函数内部申请）而言更大，因此算法题更推荐申请全局变量
int a[maxr][maxr] = {0};    //记录地图
int dp1[2][maxr] = {0};     //方法1，滚动数组
int dp2[maxr] = {0};              //方法2，数组降维
int res = 0;
int r;

int main(void) {
    cin >> r;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=i; j++) {
            cin >> a[i][j]; 
        }
    }

    // 方法1：滚动数组
    // for (int i=1; i<=r; i++) {
    //     for (int j=1; j<=i; j++) {
    //         dp1[i%2][j] = max(dp1[(i-1)%2][j-1], dp1[(i-1)%2][j]) + a[i][j];    //滚动数组&状态转移方程
    //         cout << dp1[i%2][j] << " ";
    //         res = max(dp1[i%2][j], res);
    //     }
    //     cout << endl;
    // }

    //方法2：数组降维
    fp(i, 1, r) {
        fd(j, i, 1) {
            dp2[j] = max(dp2[j], dp2[j-1]) + a[i][j];   //状态方程
            cout << dp2[j] << " ";
            res = max(res, dp2[j]);
        }
        cout << endl;
    }
    
    
    // for (int i=1; i<=r; i++) res = max(map[r%2][i], res);
    // cout << res;

    _getch();
    return 0;
}


