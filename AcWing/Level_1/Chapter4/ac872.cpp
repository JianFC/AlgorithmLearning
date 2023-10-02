#include <iostream>

using namespace std;        //AcWing 872. 最大公约数

int gcd(int a, int b) {     
    return b ? gcd(b, a % b): a;
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n --) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }

    return 0;
}