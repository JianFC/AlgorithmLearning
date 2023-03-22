#include <iostream>
#include <algorithm>
#include <math.h>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;

int main(void) {
    int s, m, t;
    cin >>  m >> t >> s;
    if (t==0 && s==0) cout << m;
    else if (t==0 && s>0) cout << 0;
    else if (t!=0 && s>=0){
        int temp =  m - ceil(float(s)/t);
        cout << (temp>=0? temp : 0);
    } 


    _getch();
    return 0;
}