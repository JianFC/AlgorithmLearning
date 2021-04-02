//回溯法，解空间树（子集树or排列树），深搜
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn=15;
int a[maxn];    //由题目可知，每一列都必定有一个皇后，a[i]表示第i列皇后所在的行位置（行号）
int n;
int res = 0;

//剪枝函数
inline bool check(int t) {
    for (int i=1; i<t; i++) {
        if (abs(t-i)==abs(a[t]-a[i]) || a[t]==a[i]) return false;
    }
    return true;
}

//回溯主函数
inline void backtrack(int t) {
    if (t>n) res++;
    else {
        fp(i, 1, n) {
            a[t] = i;
            if (check(t)) backtrack(t+1);   
        }
    }
}

int main(void) {
    // ios::sync_with_stdio(false);
    cin >> n;
    backtrack(1);
    cout << res;
    _getch();
    return 0;
}