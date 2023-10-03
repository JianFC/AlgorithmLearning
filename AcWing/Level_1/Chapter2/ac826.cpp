#include <iostream>

using namespace std;        //AcWing 826. 单链表

const int N = 100010;

// head表示头结点的下标
// e[i]表示结点i的值
// ne[i]表示结点i的后一个结点下标
// idx表示当前已经使用到了哪个点
int head, e[N], ne[N], idx;

//初始化
void init() {       
    head = -1, idx = 0;
}

//将x插到头结点
void add_to_head(int x) {
    e[idx] = x, ne[idx] = head, head = idx++;
}

//将x插到第k个结点之后
void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

//将下标是k的点的后面的点删掉
void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main(void) {
    int m;
    scanf("%d", &m);

    init();

    while (m --) {
        int k, x;
        char op;
        // scanf("%c", &op);
        cin >> op;

        if (op == 'H') {
            scanf("%d", &x);
            add_to_head(x);
        }
        else if (op == 'D') {
            scanf("%d", &k);
            if (!k) head = ne[head];
            else remove(k - 1);
        }
        else {
            scanf("%d%d", &k, &x);
            add(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i]) printf("%d ", e[i]);

    return 0;
}