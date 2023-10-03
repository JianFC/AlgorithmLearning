#include <iostream>

using namespace std;        //AcWing 837. 连通块中点的数量

const int N = 100010;

int n, m;
int p[N], cnt[N];   //cnt[i] i所在集合中结点的个数，只保证集合数中根结点的cnt正确。

int find(int x) {       
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(void) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) p[i] = i, cnt[i] = 1;  //初始化p和cnt数组

    while (m --) {
        int a, b;
        char op[3];
        scanf("%s", op);

        if (op[0] == 'C') {
            scanf("%d%d", &a, &b);
            a = find(a), b = find(b);
            p[a] = b;
            if (a != b) cnt[b] += cnt[a];   //a和b不在同一个集合，才更新b
        }
        else if (op[1] == '1') {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else {
            scanf("%d", &a);
            printf("%d\n", cnt[find(a)]);
        }
    }

    return 0;
}