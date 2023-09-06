#include <iostream>

using namespace std;

bool is_prime(int x) {      //AcWing 866. 试除法判定质数
    if (x < 2) return false;
    else
        //不推荐写成i*i<=x, 当x接近int最大值时存在溢出风险
        //也不建议写成i <= sqrt(x)，sqrt函数运算较慢
        for (int i = 2; i <= x / i; i++)    
            if (x % i == 0) return false;

    return true;
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        int a;
        scanf("%d", &a);

        if (is_prime(a)) puts("Yes");
        else puts("No");
    }

    return 0;
}