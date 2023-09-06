#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N];   //p[N]存储每个节点的父节点是谁

//返回x的祖宗结点 + 路径压缩
int find(int x) {       //AcWing 836. 合并集合
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];    //注意一定是返回p[x]
}

int main(void) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) p[i] = i;

    while (m--) {
        int a, b;
        char op[2];
        scanf("%s%d%d", op, &a, &b);

        if (op[0] == 'M') p[find(a)] = find(b);     //a的祖宗节点设为b
        else {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}