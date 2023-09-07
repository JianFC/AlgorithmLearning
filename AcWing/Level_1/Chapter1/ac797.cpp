#include <iostream>

using namespace std;    //AcWing 797. 差分

const int N = 1e5+10;

int n, m;
int a[N], b[N];     //b表示差分数组

void insert(int l, int r, int c) {      //插入函数 
    b[l] += c;
    b[r + 1] -= c;
}

int main(void) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) insert(i, i, a[i]);    //利用插入函数构造差分数组

    while (m--) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    //由差分数组构造出原数组
    for (int i = 1; i <= n; i++) b[i] += b[i - 1], printf("%d ", b[i]); 

    return 0;
}
