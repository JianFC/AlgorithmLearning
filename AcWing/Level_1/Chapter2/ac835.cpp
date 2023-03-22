#include <iostream>

using namespace std;

const int N = 100010;

char str[N];
int son[N][26], cnt[N], idx;    //cnt[i] i所在集合中结点的个数，只保证集合数中根结点的cnt正确。

void insert(char *str) {    //AcWing 835. Trie字符串统计
    int p = 0;
    for (int i=0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }

    cnt[p]++;
}

int query(char *str) {
    int p = 0;
    for (int i=0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }

    return cnt[p];
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[2];
        scanf("%s%s", op, str);

        if (op[0] == 'I') insert(str);
        else printf("%d\n", query(str));
    }

    return 0;
}