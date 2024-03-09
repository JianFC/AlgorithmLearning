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
    int t;
    cin >> t;
    const float PI = 3.141593;
    switch(t) {
    case 1:
        cout << "I love Luogu!" << endl;
        break;
    case 2:
        cout << 6 << " " << 4;
        break;
    case 3:
        cout << 3 << endl << 12 << endl << 2;
        break;
    case 4:
        printf("%.3f", float(500)/3);
        break;
    case 5:
        cout << 15;
        break;
    case 6:
        cout << sqrt(6*6+9*9);
        break;
    case 7:
        cout << 110 << endl << 90 << endl << 0 << endl; 
        break;
    case 8:
        cout << 2*PI*5 << endl << PI*5*5 << endl << (double)4/3*PI*125<<endl;
        break;
    case 9:
        cout << 22;
        break;
    case 10:
        cout << 9;
        break;
    case 11:
        cout << double(100)/3;
        break;
    case 12:
        cout << 13 << endl << "R";
        break;
    case 13:
        cout << int(pow(float(4)/3*PI*(64+1000), 1.0*1/3));
        break;          
    case 14:
        cout << 50;
        break;
    }

    _getch();
    return 0;
}