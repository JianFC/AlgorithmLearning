#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int h[N];

int find(int x) {   //AcWing 840. 模拟散列表开放寻址法
    int k = (x%N+N)%N;

    while (h[k]!=null && h[k]!=x) {
        k++;
        if (k == N) k = 0;
    }

    return k;
}

int main(void) {
    int n;
    scanf("%d", &n);

    memset(h, 0x3f, sizeof h);

    while (n--) {
        int x;
        char op[2];
        scanf("%s%d", op, &x);

        if (*op == 'I') h[find(x)] = x;
        else {
            if (h[find(x)] == null) puts("No");
            else puts("Yes");
        }
    }

    return 0;
}