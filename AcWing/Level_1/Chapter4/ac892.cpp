#include <iostream>

using namespace std;        //AcWing 892. 台阶-Nim游戏

int main(void) {    
    int n;
    scanf("%d", &n);

    int res = 0;
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        if (i & 1) res ^= x;    //只需异或上奇数级台阶上的石子
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}