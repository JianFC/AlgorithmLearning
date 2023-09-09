#include <iostream>

using namespace std;    //AcWing 790. 数的三次方根

int main(void) {
    double x;
    scanf("%lf", &x);

    double l = -100, r = 100;

    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }

    printf("%.6lf", l);

    return 0;
}