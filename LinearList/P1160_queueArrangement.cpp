#include <iostream>
#include <algorithm>
#include <list>
#include <cstdio>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++) 
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;

// -----------------------------使用stl中list，未优化TLE__开始-------------------------------------
const int maxn = 1e5+5;
list<int> li;
int n, m;
int k, p;
int x;

inline void insertion (void) {
    fp(i, 2, n) {
        cin >> k >> p;
        list<int>::iterator pos = find(li.begin(), li.end(), k);
        if (pos!=li.end()) {
            if (p==0) li.insert(pos, i);
            else {
                if (pos++ != li.end()) li.insert(pos++, i);
                else li.push_back(i);
            }
        }
    }
}

inline void deletion (void) {
    fp(i, 1, m) {
        cin >> x;
        list<int>::iterator pos = find(li.begin(), li.end(), x);
        if (pos!=li.end()) li.erase(pos);
    }
}


int main(void) {
    cin >> n;
    li.push_back(1);
    insertion();

    cin >> m;
    deletion();

    for (list<int>::iterator it=li.begin(); it!=li.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    _getch();
    return 0;
}
// -----------------------------使用list，未优化TLE__结束-------------------------------------