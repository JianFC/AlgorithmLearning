#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;        //265. 营业额统计

typedef long long LL;

const int N = 33010, INF = 1e7;

int n;
struct Node {
    int l, r;
    int key, val;
}tr[N];

int root, idx;

int get_node(int key) {
    tr[++ idx].key = key;
    tr[idx].val = rand();
    return idx;
}

void zig(int &p) {
    int q = tr[p].l;
    tr[p].l = tr[q].r, tr[q].r = p, p = q;
}

void zag(int &p) {
    int q = tr[p].r;
    tr[p].r = tr[q].l, tr[q].l = p, p = q;
}


void build() {
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
    
    if (tr[2].val > tr[1].val) zag(root);
}

void insert(int &p, int key) {
    if (!p) p = get_node(key);
    else if (tr[p].key == key) return;  //不需要维护cnt和size
    else if (tr[p].key > key) {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val) zig(p);
    }
    else {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val) zag(p);
    }
}

int get_prev(int p, int key) {
    if (!p) return -INF;
    if (tr[p].key > key) return get_prev(tr[p].l, key);    //注意找<=的最大值，因此条件为>
    return max(tr[p].key, get_prev(tr[p].r, key));
}

int get_next(int p, int key) {
    if (!p) return INF;
    if (tr[p].key < key) return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));
}


int main(void) {
    build();
    
    scanf("%d", &n);
    LL res = 0;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        
        if (i == 0) res += x;
        else res += min(x - get_prev(root, x), get_next(root, x) - x);
        
        insert(root, x);
    }
    
    printf("%lld\n", res);
    
    
    return 0;
}