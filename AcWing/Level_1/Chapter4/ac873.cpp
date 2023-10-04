#include <iostream>

using namespace std;        //AcWing 873. 欧拉函数

// 返回欧拉函数值
int phi(int x) {        
    int res = x;

    for (int i = 2; i <= x / i; i ++) {
        if (x % i == 0) {
            res = res / i * (i - 1);  //整数不支持小数除法，将res * (1 - 1 / i)变换为res / i * (i - 1)
            while (x % i == 0) x /= i;
        }
    }

    if (x > 1) res = res / x * (x - 1);

    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n --) {
        int a;
        scanf("%d", &a);

        cout << phi(a) << endl;
    }

    return 0;
}