#include <iostream>

using namespace std;        //AcWing 829. 模拟队列

const int N = 100010;

int q[N], hh, tt = -1;

int main(void) {    
    int m;
    scanf("%d", &m);

    while (m --) {
        int x;
        string op;
        cin >> op;

        if (op == "push") {
            scanf("%d", &x);
            q[++ tt] = x;
        }
        else if (op == "pop") hh++;
        else if (op == "empty") {
            if (hh <= tt) puts("NO");
            else puts("YES");
        }
        else printf("%d\n", q[hh]);
    }

    return 0;
}
