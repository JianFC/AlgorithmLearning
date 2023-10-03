#include <iostream>

using namespace std;        //AcWing 830. 单调栈

const int N = 100010;

int stk[N], tt;

int main(void) {    
    int n;
    scanf("%d", &n);

    while (n --) {
        int x;
        scanf("%d", &x);

        while (tt && stk[tt] >= x) tt --;    //结合画图理解
        if (tt) printf("%d ", stk[tt]);
        else printf("-1 ");

        stk[++ tt] = x;
    }

    return 0;
}
