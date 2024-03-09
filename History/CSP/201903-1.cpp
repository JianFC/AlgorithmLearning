//注意输出格式的控制！

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
int Max = 0, Min = 0;
int Mid = 0;
float Midf = 0;
int n;

int main(void) {
    int midindex, flag, temp;
    cin >> n;
    if (n % 2 == 0) { midindex = n/2; flag=2; }
    else { midindex = n/2+1; flag=1; }
    fp(i, 1, n) {
        cin >> temp;
        if (i==1) Max = temp;
        else if (i==n) Min = temp;
        else if (flag == 2 && (i==midindex || i==midindex+1)) Mid += temp;
        else if (flag == 1 && i==midindex) Mid = temp;
        else continue;
    }

    if (flag == 2 && Mid%2==0) { Mid /=2; flag = 1; }
    else if (flag == 2 && Mid%2!=0) {Midf = float(Mid)/2; flag=2;}

    if (Max < Min) { temp = Max; Max = Min; Min = temp; }
    
    if (flag == 2) printf("%d %.1f %d", Max, Midf, Min);
    else if (flag == 1) printf("%d %d %d", Max, Mid, Min);

    _getch();
    return 0;
}