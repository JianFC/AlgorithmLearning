#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
const int maxn = 1e3 + 5;
const int maxm = 110;
int a[maxn];    //文章单词数组
vector<int> mem;   //内存
int m, n;
int cnt = 0;

int main(void) {
    cin >> m >> n;
    vector<int>::iterator pos;
    fp(i, 1, n) cin >> a[i];

    fp(i, 1, n) {
        pos = find(mem.begin(), mem.end(), a[i]);
        if (pos==mem.end()) {
            cnt++;
            mem.push_back(a[i]);    //加入内存
            if (int(mem.size())>m) mem.erase(mem.begin());
        }
    }

    cout << cnt;

    _getch();
    return 0;
} 