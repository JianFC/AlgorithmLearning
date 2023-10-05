#include <iostream>
#include <cstring>

using namespace std;        //AcWing 840. 模拟散列表开放寻址法

const int N = 200003, null = 0x3f3f3f3f;    //null不在x范围内的一个数，标记

int h[N];

int find(int x) {   
    int k = (x % N + N) % N;    //哈希函数

    while (h[k] != null && h[k] != x) {     //当x存在哈希表中时，返回x的位置，不存在时，返回x应该存储的位置
        k ++;
        if (k == N) k = 0;  //防止越界，循环操作
    }

    return k;
}

int main(void) {
    int n;
    scanf("%d", &n);

    memset(h, 0x3f, sizeof h);

    while (n --) {
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