#include <iostream>

using namespace std;

void divide(int x) {        //AcWing 867. 分解质因数
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int s = 0;
            while (x % i == 0) x /= i, s++;
            printf("%d %d\n", i, s);
        }
    }

    //x中最多只包含一个大于sqrt(x)的质因子
    if (x > 1) printf("%d 1\n", x);
    puts("");
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        int a;
        scanf("%d", &a);
        divide(a);
    }

    return 0;
}