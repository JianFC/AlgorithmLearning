#include <iostream>

using namespace std;      //AcWing 828. 模拟栈

const int N = 100010;

int stk[N], tt;

int main(void) {    
    int m;
    scanf("%d", &m);

    while (m --) {
        int x;
        string op;
        cin >> op;

        if (op == "push") {
            scanf("%d", &x);
            stk[++ tt] = x;
        }
        else if (op == "pop") tt --;
        else if (op == "empty") {
            if (tt > 0) puts("NO");
            else puts("YES");
        }
        else printf("%d\n", stk[tt]);
    }

    return 0;
}
