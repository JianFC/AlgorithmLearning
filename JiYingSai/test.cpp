#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <conio.h>
#include <cstring>
#include <cstdio>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
class Test{
    public:
    Test(){ cout << "Test()" << endl; }
    ~Test(){ cout << "~Test()" << endl; }
};

int fun (int x, double y, int z) {
    return 1;
}
double fun(double x, int y, int z) {
    return 1.1;
}

int main(void) {
    Test test[2], *pTest[2];
    int a[][4] = {1, 2};
    
    _getch();
    return 0;
}