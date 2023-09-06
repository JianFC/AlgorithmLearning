#include <iostream>

using namespace std;

const int N = 2010, mod = 1e9+7;

int c[N][N];

void init() {       //AcWing 885. 求组合数 I
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (!j) c[i][j] = 1;    //当j=0时，进行特判
            else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
}

int main(void) {
    init();

    int n;
    scanf("%d", &n);

    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", c[a][b]);
    }

    return 0;
}
