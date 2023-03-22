#include <iostream>

using namespace std;

const int N = 100010;

int lowbit(int x) {     //AcWing 801. 二进制中1的个数
    return x&-x;
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        int x;
        scanf("%d", &x);

        int res = 0;
        while (x) x -= lowbit(x), res++;

        printf("%d ", res);
    }

    return 0;
}
