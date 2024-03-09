#include <iostream>
#include <algorithm>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 110;
int visit[maxn];
int n, m;
int cnt=0;

int main(void) {
    cin >> n >> m;

    fp(i, 1, n) {
        fp(j, 1, m) {
            ++cnt;
            if (cnt>n) cnt = 1;
            if (visit[cnt]) j--;     //此处使用j--使内循环暂时停止，从而跳过已出队的人
        }
        cout << cnt << " ";
        visit[cnt] = 1;
    }

    _getch();
    return 0;
}


