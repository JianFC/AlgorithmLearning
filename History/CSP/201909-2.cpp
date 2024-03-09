#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1e3+10;
struct node {
    int rem, flag1; //rem代表苹果树上目前的苹果数量，flag1代表其是否发生苹果掉落
} tree[maxn];
int n, m;
int res[4]; //res[1-3]分别代表T,D,E

int main(void) {
    int a;
    cin >> n;
    int flag2;
    fp(i, 1, n) {
        cin >> m >> a; 
        tree[i].rem = a; res[1]+=a; flag2 = 1;
        fp(j, 2, m) {
            cin >> a;
            if (a<=0) { tree[i].rem += a; res[1] += a; }
            else {
                if (tree[i].rem > a) {
                    tree[i].flag1 = 1; //有苹果掉落
                    res[1] -= (tree[i].rem-a);  //更新T
                    if (flag2) { res[2]++; flag2 = 0; } //更新D
                    tree[i].rem = a;
                }
            }
        }

    }
    
    fp(i, 1, n) {
        flag2 = 1;
        if (tree[i].flag1 == 0) {i++; continue;}    //i++跳过下一棵苹果树
        else {
            if (i==1 && tree[n].flag1==1 && tree[2].flag1==1) res[3]++;
            else if (i==n && tree[n-1].flag1==1 && tree[1].flag1==1) res[3]++;
            else {
                if (tree[i-1].flag1==1 && tree[i+1].flag1==1) res[3]++;
                else continue;
            }
        }
    }

    cout << res[1] << " " << res[2] << " " << res[3];

    _getch();
    return 0;
}