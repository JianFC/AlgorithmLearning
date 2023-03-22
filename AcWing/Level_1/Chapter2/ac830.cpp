#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], tt;

int main(void) {    //AcWing 830. 单调栈
    int n;
    scanf("%d", &n);

    while (n--) {
        int x;
        scanf("%d", &x);

        while (tt && stk[tt]>=x) tt--;
        if (tt) printf("%d ", stk[tt]);
        else printf("-1 ");

        stk[++tt] = x;
    }

    return 0;
}
