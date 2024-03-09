#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;

int main(void) {
    float a, b, c;
    cin >> a >> b >> c;
    float p = (a+b+c)/2;
    ll res = p*(p-a)*(p-b)*(p-c);
    printf("%.1f", sqrt(res));

    _getch();
    return 0;
}