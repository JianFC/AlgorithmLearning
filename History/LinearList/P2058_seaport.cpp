#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
//------------------------------模拟队列AC__开始------------------------------------------
using namespace std;
const int maxn = 1e5+5;
const int maxk = 3e5+5;     //最多总的乘客数
const int maxx = 1e5+5;
struct node{
    int x, t;   //p[i].x代表第i个乘客的国籍，p[i].t代表第i个乘客到达的时间

} que[maxk];  //记录24小时内每个乘客到达的时间与其国籍的模拟队列
int f=1, r=0;   //f代表队头，r代表队尾。初始f=1,r=0;
int n;
int res;    //存储累计结果
int ti, ki;     //ti和ki分别表示这艘船到达海港的时间和船上的乘客数量
int xi;     //xi暂存乘客的国籍
int xnum[maxx] = {0};   //x[i]代表24小时内国籍为i的乘客的总数

int main(void) {
    cin >> n;
    fp(i, 1, n) {
        cin >> ti >> ki;
        fp(j, 1, ki) {
            cin >> xi;
            que[++r].t = ti;    //元素入队
            que[r].x = xi;
            if (xnum[xi] == 0) res++;
            xnum[xi]++;
        }

        while(ti-que[f].t >= 86400 && f<=r) {
            xnum[que[f].x]--; 
            if (xnum[que[f].x] == 0) res--;     //当进行到第i次循环时，res的值为第i-1次的res+第i次新增的国籍数目，
                                            //此时需要动态减掉第i-1次res中包含的只存在于，以如今ti为基准24小时之前的国籍的数目。
            f++;    //队首元素出队
        }

        cout << res << endl;

    }

    _getch();
    return 0;
}
//------------------------------模拟队列AC__结束------------------------------------------

//----------------------------------------TLE__开始-------------------------------------------
// struct node{
//     int x, t;   //p[i].x代表第i个乘客的国籍，p[i].t代表第i个乘客到达的时间
// } p[maxn];  //记录每个乘客到达的时间与其国籍
// int n;
// int res[maxn] = {0};    //存储结果
// int ti, ki;     //ti和ki分别表示这艘船到达海港的时间和船上的乘客数量
// int cnt = 0;    //到达的乘客计数
// int xflag[maxx] = {0};

// int main(void) {
//     cin >> n;
//     fp(i, 1, n) {
//         cin >> ti >> ki;
//         memset(xflag, 0, sizeof(xflag));
//         fp(j, 1, ki) {
//            p[++cnt].t = ti;
//            cin >> p[cnt].x; 
//         }
//         for (register int k=cnt; p[k].t>ti-86400 && k>=1; k--) {
//             if (xflag[p[k].x] == 0) res[i]++;
//             xflag[p[k].x] = 1;
//         }
//         cout << res[i] << endl;
//     }

//     _getch();
//     return 0;
// }
//----------------------------------------TLE__结束-------------------------------------------

//----------------------------------------TLE__开始-------------------------------------------
// struct node{
//     int t;          //记录船t[i]到达的时刻
//     int k;          //记录船t[i]上的乘客数
//     vector<int> x;  //记录t[i]船上所有乘客的国籍
// } t[maxn];  
// int n;      
// int xi;
// int res[maxn];  //存储结果
// int ptime;
// int xflag[maxx] = {0};   


// int main(void) {
//     cin >> n;
//     fp(i, 1, n) {
//         cin>> t[i].t >> t[i].k;
//         fp(j, 1, t[i].k) {
//             cin >> xi;
//             t[i].x.push_back(xi);
//         }
//     }

//     fp(i, 1, n) {
//         ptime = t[i].t - 86400;
//         memset(xflag, 0, sizeof(xflag));
//         for (int j=i; t[j].t>ptime && j>=1; j--) {
//             for (int r=0; r<int(t[j].x.size()); r++) {
//                 if(xflag[t[j].x[r]] == 0) res[i]++;
//                 xflag[t[j].x[r]] = 1;
//             }
//         }
//         cout << res[i] << endl;
//     }

//     _getch();
//     return 0;
// }
//----------------------------------------TLE__结束-------------------------------------------