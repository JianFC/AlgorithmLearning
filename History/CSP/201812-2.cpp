#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
int r, y, g;
int n;
int k, t;
ll time = 0;    //注意数据范围，最坏情况下10^5x3x10^6以超过int范围，int最多10^10（2147483647）

int main(void) {
    cin >> r >> y >> g;
    cin >> n;
    int temp;
    fp(i, 1, n) {
        cin >> k >> t;
        switch(k) {
            case 0: time += t; break;
            case 1: 
                temp = time % (r+y+g);
                if (temp <= t) time += (t-temp);
                else {
                    temp = temp - t;
                    if (temp>g && temp<=g+y) time = time + (y+g-temp) + r;  //处于黄灯
                    else if (temp>g+y && temp<r+y+g) time = time + (r+y+g-temp); //处于红灯
                }
                break;
            case 2:
                temp = time %(r+y+g);   //注意变量名等细节！
                if (temp <= t) time += (t-temp) + r;
                else {
                    temp = temp-t;
                    if (temp>0 && temp<=r) time += (r-temp);    //处于红灯
                    else if (temp>r+g && temp<=r+y+g) time += (r+y+g-temp) + r;  //处于黄灯
                }
                break;
            case 3:
                temp = time %(r+y+g);
                if(temp > t) {
                    temp = temp-t;
                    if (temp>0 && temp<=y) time += (y-temp)+r;    //处于黄灯
                    else if (temp>y && temp<=r+y) time += (r+y-temp);  //处于红灯
                }
                break;
        }
    }
    cout << time;

    _getch();
    return 0;
}