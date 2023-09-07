#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 100010, P = 131;      //当p=131 or 13331时，冲突概率最小

int n, m;
char str[N];
ULL h[N], p[N];     //h数组预处理字符串每个前缀的hash值，p[i]存储p的i次幂

ULL get(int l, int r) {     //AcWing 841. 字符串哈希
    return h[r] - h[l - 1] * p[r - l + 1];      //任意子串hash公式
}

int main(void) {
    scanf("%d%d%s", &n, &m, str + 1);

    p[0] = 1;
    for (int i = 1; i <= n; i++) {      //预处理p数组和h数组
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];   //保证h[i]不等于0
    }

    while (m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        if (get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }

    return 0;
}