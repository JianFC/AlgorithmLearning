#include <iostream>
#include <algorithm>
#include <list>
#include <cstdio>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++) 
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1e5+5;
struct li {
    int l, r;   //l代表其左手牵的同学，r代表其右手签的同学
    int flag;   //flag为1代表其不在队列中，为0代表在队列中。
} t[maxn] = {0};
int n, m;
int k, p;
int x;

void add(int i, int k, int p) {
    //画图理解
    if (p==1) {
        t[i].r = t[k].r;
        t[k].r = i;
        t[i].l = k;
        t[t[i].r].l = i;     
    } 
    else {
        t[i].l = t[k].l;
        t[k].l = i;
        t[i].r = k;
        t[t[i].l].r = i;
    }
}

int main(void) {
    t[0].l=0; t[0].r=0; //插入一个0结点，为整个链表的起点
    add(0, 1, 1);   //将第一个同学插入链表中
    cin >> n;
    fp(i, 2, n) {
        cin >> k >> p;
        add(i, k, p);
    }

    cin >> m;
    fp(i, 1, m) {
        cin >> x;
        t[x].flag = 1;  //将第x号同学flag置1，代表其出队
    }

    for (int i=t[0].r; i; i=t[i].r) {
        if (t[i].flag == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    _getch();
    return 0;
}

// -----------------------------使用stl中list，未优化TLE__开始-------------------------------------
// const int maxn = 1e5+5;
// list<int> li;
// int n, m;
// int k, p;
// int x;

// inline void insertion (void) {
//     fp(i, 2, n) {
//         cin >> k >> p;
//         list<int>::iterator pos = find(li.begin(), li.end(), k);
//         if (pos!=li.end()) {
//             if (p==0) li.insert(pos, i);
//             else {
//                 if (pos++ != li.end()) li.insert(pos++, i);
//                 else li.push_back(i);
//             }
//         }
//     }
// }

// inline void deletion (void) {
//     fp(i, 1, m) {
//         cin >> x;
//         list<int>::iterator pos = find(li.begin(), li.end(), x);
//         if (pos!=li.end()) li.erase(pos);
//     }
// }


// int main(void) {
//     cin >> n;
//     li.push_back(1);
//     insertion();

//     cin >> m;
//     deletion();

//     for (list<int>::iterator it=li.begin(); it!=li.end(); it++) {
//         cout << *it << " ";
//     }
//     cout << endl;

//     _getch();
//     return 0;
// }
// -----------------------------使用list，未优化TLE__结束-------------------------------------