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
struct point {
    int x, y;   //点(x, y)坐标
    char type;  //type类型
    point(){}
    point(int x, int y ,char type): x(x), y(y), type(type){}
} poi[maxn];
int n, m, a1, a2, a3;   //a1, a2, a3分别代表直线的参数
int cat[256];  //cat['A']代表A类点在直线下的类别，cat['B']代表B类点在直线下的类别

int main(void) {
    int flag, temp;
    cin >> n >> m;
    fp(i, 1, n) cin >> poi[i].x >> poi[i].y >> poi[i].type;
    fp(i, 1, m) {
        cin >> a1 >> a2 >> a3;
        flag = 1; 
        memset(cat, 0, sizeof(cat));

        fp(ii, 1, n) {
            temp = a1 + a2*poi[ii].x + a3*poi[ii].y;
            temp = temp > 0 ? 1 : -1;   //对temp进行归一化

            if (poi[ii].type == 'A') {
                if (cat['A'] == 0) { cat['A'] = temp; }
                else {
                    if (temp == cat['A']) continue;
                    else { flag = 0; break; }
                }
            }
            if (poi[ii].type == 'B') {
                if (cat['B'] == 0) { cat['B'] = temp; }
                else {
                    if (temp == cat['B']) continue;
                    else { flag = 0; break; }
                }
            }
        }

        printf("%s\n", flag == 1? "Yes" : "No");
    }

    _getch();
    return 0;
}
