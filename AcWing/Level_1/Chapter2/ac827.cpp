#include <iostream>

using namespace std;

const int N = 100010;

int head, l[N], r[N], e[N], idx;

//初始化双链表
void init() {       //AcWing 827. 双链表
    //0表示最左端结点，1表示最右边结点，起标志作用，不能被删除或修改
    //idx从2开始
    r[0] = 1, l[1] = 0;
    idx = 2;
}

//在第k个插入的结点右侧插入一个结点
void add(int k, int x) {
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx++;
}

//删除第k个插入的结点
void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main(void) {
    int m;
    scanf("%d", &m);

    init();

    while (m--) {
        int k, x;
        string op;
        cin >> op;

        if (op == "L") {
            scanf("%d", &x);
            add(0, x);
        }
        else if (op == "R") {
            scanf("%d", &x);
            add(l[1], x); 
        }
        else if (op == "D") {
            scanf("%d", &k);
            remove(k+1);
        }
        else if (op == "IL") {
            scanf("%d%d", &k, &x);
            add(l[k+1], x);
        }
        else {
            scanf("%d%d", &k, &x);
            add(k+1, x);
        }
    }

    for (int i=r[0]; i!=1; i=r[i]) printf("%d ", e[i]);

    return 0;
}
