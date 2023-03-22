#include <iostream>

using namespace std;

int main(void) {    //AcWing 891. Nim游戏
    int n;
    scanf("%d", &n);

    int res = 0;
    while (n--) {
        int x;
        scanf("%d", &x);
        res ^= x;
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}