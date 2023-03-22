//类约瑟夫问题
#include <iostream>
#include <algorithm>
#include <vector>
#include <conio.h>
#include <cstring>
#include <cstdio>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1e3+10;
struct node {
    int re, cut, id;    //re代表剩余的个数，cut代表疏果的个数，id代表其编号，用于排序
} tree[maxn];
//排序仿函数,用于sort函数

bool cmp (node a, node b) {
    if (a.cut > b.cut) return true;
    else if (a.cut == b.cut && a.id < b.id) return true;
    else return false;
}

int n, m;
int t = 0, k, p;

int main(void) {
    int aim;
    cin >> n >> m;
    fp(i, 1, n) {
        cin >> tree[i].re; tree[i].id = i;
        t += tree[i].re;
        fp(j, 1, m) {
            cin >> aim; //注意aim是负数
            tree[i].re += aim; tree[i].cut -= aim; t+=aim;
        }
    }
    sort(tree+1, tree+1+n, cmp);
    cout << t << " " << tree[1].id << " " << tree[1].cut;

    _getch();
    return 0;
}

