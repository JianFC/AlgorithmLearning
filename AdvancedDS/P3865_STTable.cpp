// P3865 【模板】ST表

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(l); i--)
typedef long long ll;

using namespace std;
const int maxn = 1e5+10;
int poww[30], logg[maxn];   //poww[i]表示2的i次方, logg[i]表示以2为底，i的对数向下取整
int a[maxn][30];    //a[i][j]表示从i到i+(2^j)-1区间内的最大值，该区间一共包含2^j个元素
int n, m;

int main(void){
    scanf("%d %d", &n, &m);
    fp(i, 1, n) scanf("%d", &a[i][0]);

    // 预处理poww与logg数组
    poww[0]=1; for (int i=1; i<=30; i++) poww[i] = poww[i-1]<<1;
    logg[0]=-1; for (int i=1; i<=n; i++) logg[i] = logg[i/2]+1;

    // 预处理a[maxn][30]，核心部分，类似LCA中倍增思想
    for (int j=1; j<=logg[n]; j++) {
        for (int i=1; i<=n; i++) {
            if (i+poww[j]-1<=n) {
                a[i][j] = max(a[i][j-1], a[i+poww[j-1]][j-1]);
            }
        }
    }

     // 定理：2^logg(x)>x/2
    int l, r, len, loglen;
    fp(i, 1, m) {
        scanf("%d %d", &l, &r);
        len = r-l+1; loglen = logg[len];
        printf("%d\n", max(a[l][loglen], a[r-poww[loglen]+1][loglen])); //注意只能使用poww[loglen]，不能使用len, poww[loglen]不一定等于len
    }

    _getch();
    return 0;
}


