#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx;     //单链表的应用

void insert(int x) {    //AcWing 840. 模拟散列表拉链法
    int k = (x % N + N) % N;    //哈希函数，C++取模可能为负数，+N % N 使x映射到[0, N - 1]的位置

    e[idx] = x, ne[idx] = h[k], h[k] = idx++;   //插入操作
}

bool find(int x) {
    int k = (x % N + N) % N;    //哈希函数

    for (int i = h[k]; i != -1; i = ne[i])  //遍历链表 
        if (e[i] == x)
            return true;

    return false;
}

int main(void) {
    // for (int i=100000; ; i++) {  //找到大于100000的第一个质数
    //     bool flag = true;
    //     for (int j=2; j*j<=i; j++) {
    //         if (i%j == 0) {
    //             flag = false;
    //             break;
    //         }
    //     }

    //     if (flag) {
    //         cout << i << endl;
    //         break;
    //     }
    // }

    int n;
    scanf("%d", &n);

    memset(h, -1, sizeof h);

    while (n--) {
        int x;
        char op[2];
        scanf("%s%d", op, &x);

        if (*op == 'I') insert(x);
        else {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}