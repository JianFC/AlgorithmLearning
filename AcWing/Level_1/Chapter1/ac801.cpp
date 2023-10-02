#include <iostream>

using namespace std;    //AcWing 801. 二进制中1的个数

const int N = 100010;

int lowbit(int x) {     
    return x & -x;
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n --) {
        int x;
        scanf("%d", &x);

        int res = 0;
        while (x) x -= lowbit(x), res++;    //每次减去x的最后一位1，res++

        printf("%d ", res);
    }

    return 0;
}
