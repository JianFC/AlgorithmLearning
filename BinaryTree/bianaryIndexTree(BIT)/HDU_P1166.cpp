//HDU P1166 敌兵布阵
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(l); i--)
#define lowbit(x) (x)&(-x)
typedef long long ll;

using namespace std;
const int maxn = 5e4+10;
int tree[maxn];
int n;

inline void update(int i, int x) {
    for (int pos=i; pos<=maxn; pos+=lowbit(pos)) {
        tree[pos]+=x;
    }
}

inline int query(int n) {
    int ans = 0;
    for (int pos=n; pos; pos-=lowbit(pos)) {
        ans+=tree[pos];
    }
    return ans;
}

inline int query(int i, int j) {
    return query(j)-query(i-1);
}

int main(void) {
    int t; cin >> t;
    int x;
    int op1, op2;
    char ch[5];
    fp(k, 1, t) {
        memset(tree, 0, sizeof(tree));
        cout << "Case " << k <<":"<< endl;
        cin >> n;
        fp(i, 1, n) {
            cin >> x;
            update(i, x);
        }
        cin >> ch;
        while (ch[0]!='E'){
            cin >> op1 >> op2;
            switch(ch[0]) {
                case 'A': update(op1, op2); break;
                case 'S': update(op1, -op2); break;
                case 'Q': cout << query(op1, op2) << endl; break;
                default: break;
            }
            cin >> ch;
        }

    }

    _getch();
    return 0;
}