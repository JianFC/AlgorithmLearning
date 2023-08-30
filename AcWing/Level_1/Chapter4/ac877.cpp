#include <iostream>

using namespace std;

int exgcd(int a, int b, int &x, int &y) {       //AcWing 877. 扩展欧几里得算法
    if (!b) {
        x = 1, y = 0;   //a*1+b*0 = gcd(a, 0) = a;
        return a;
    }

    //by + (a-a/b*b)*x = d, 经过变换，原系数y = y-a/b*x;
    int d = exgcd(b, a % b, y, x);    
    y -= a / b * x;
    return d;
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);

        int x, y;
        int d = exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }

    return 0;
}