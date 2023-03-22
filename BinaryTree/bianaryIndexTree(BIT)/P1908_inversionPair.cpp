#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
#define lowbit(x) (x)&(-x)
typedef long long ll;

using namespace std;
const int maxn = 5e5+5;
int tree[maxn];
ll res = 0;
int n;
struct node {
    int value, id;  
}seq[maxn]; 
int A[maxn];    //对seq进行离散化

inline void update(int i, int x) {
    for (int pos=i; pos<=n; pos+=lowbit(pos)) {
        tree[pos]+=x;
    }
}

inline int query(int n) {
    int ans = 0;
    for (int pos=n; pos; pos-=lowbit(pos)) {
        ans += tree[pos];
    }
    return ans;
}

inline int query(int i, int j) {
    return query(j) - query(i-1);
}

bool cmp(node a, node b) {
    if (a.value < b.value) return true;
    else if (a.value == b.value && a.id <= b.id) return true;
    else return false; 
}

int main(void) {
    cin >> n;
    fp(i, 1, n) {
        cin >> seq[i].value;
        seq[i].id = i;
    }
    sort(seq+1, seq+1+n, cmp);
    fp(i, 1, n) {
        A[seq[i].id] = i;
    }
    fd(i, n, 1){   //循环从n->1，直接求出答案。
        res+=query(A[i]);
        update(A[i], 1);
    }

    cout << res << endl;

    _getch();
    return 0;
}