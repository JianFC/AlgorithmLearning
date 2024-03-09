#include <iostream>
#include <algorithm>
#include <conio.h>
#include <cstdio>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 210;
pair<int, int> point[maxn]; //检查点位置
pair<int, int> dist[maxn];  //检查点到市民距离以及检查点编号
int x, y;   //市民坐标
int n;  //检查点个数

int main(void) {
    cin >> n >> x >> y;
    fp(i, 1, n) {
        cin >> point[i].first >> point[i].second;
        dist[i].first = (point[i].first - x)*(point[i].first - x) + (point[i].second-y)*(point[i].second-y);
        dist[i].second = i;
    }
    sort(dist+1, dist+1+n);
    cout << dist[1].second << endl << dist[2].second << endl << dist[3].second;

    _getch();
    return 0;
}