#include <iostream>
#include <algorithm>
#include <vector>
#include <conio.h>
#include <cstdio>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 25;
struct cord{
    int x, y;   //x,y分别表示市民在某时刻的x坐标与y坐标
    cord(int x, int y): x(x), y(y) {}   
};
//vector<cord> per[maxn]; //per[i]表示第i位居民的的坐标序列
int num[maxn] = {0};  //num[i]表示第i位市民坐标落在高位区域的次数, 若num[i]>=1111则表示其在高危区域逗留
int n, k, t, xl, xr, yd, yu;    //意义见题目
int res1, res2; //res1代表经过的人数，res2代表逗留的人数

inline bool check(int x, int y) {
    if (x>=xl&&x<=xr && y>=yd&&y<=yu) return true;
    else return false;
}

int main(void) {
    cin >> n >> k >> t >> xl >> yd >> xr >> yu;
    int xi, yi;
    fp(i, 1, n) {
        int flag=0; //flag记录第i位市民连续在高位区域的坐标次数
        fp(j, 1, t) {
            cin >> xi >> yi;
           // per[i].push_back(cord(xi, yi)); //存储坐标
            if(check(xi, yi)) {num[i]++;flag++;}
            else flag=0;
            
            if (flag>=k) num[i]=1111;
        }
    }

    fp(i, 1, n) {
        if (num[i]>=1) res1++;
        if (num[i]>=1111) res2++;
    }
    cout << res1 << endl << res2;

    _getch();
    return 0;
}