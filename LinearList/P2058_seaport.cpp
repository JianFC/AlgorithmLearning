#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
const int maxn = 1e5+5;
const int maxx = 1e5+5;
struct node{
    int t;          //记录船t[i]到达的时刻
    int k;          //记录船t[i]上的乘客数
    vector<int> x;  //记录t[i]船上所有乘客的国籍
} t[maxn];  
int n;      
int xi;
int res[maxn];  //存储结果
int ptime;
int xflag[maxx] = {0};   


int main(void) {
    cin >> n;
    fp(i, 1, n) {
        cin>> t[i].t >> t[i].k;
        fp(j, 1, t[i].k) {
            cin >> xi;
            t[i].x.push_back(xi);
        }
    }

    fp(i, 1, n) {
        ptime = t[i].t - 86400;
        memset(xflag, 0, sizeof(xflag));
        for (int j=i; t[j].t>ptime && j>=1; j--) {
            for (int r=0; r<int(t[j].x.size()); r++) {
                if(xflag[t[j].x[r]] == 0) res[i]++;
                xflag[t[j].x[r]] = 1;
            }
        }
        cout << res[i] << endl;
    }

    _getch();
    return 0;
}