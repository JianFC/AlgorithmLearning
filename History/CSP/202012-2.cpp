#include <iostream>
#include <cstdio>
#include <algorithm>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

//---------------------------前缀和与后缀和__时间复杂度为O(n)-------------------------
using namespace std;
const int maxm =1e5+10;
int m;
int prefix[maxm], suffix[maxm], p[maxm];    //prefix[i]前缀和，suffix[i]后缀和
pair<int, int> a[maxm];

int main(void) {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> m;
    fp(i, 1, m) cin >> a[i].first >> a[i].second;
    sort(a+1, a+1+m);   //sort默认对pair.first按升序排列，若first相同，则对second按升序排列
    //前缀和
    fp(i, 1, m) prefix[i] = prefix[i-1] + (a[i].second == 0 ? 1 : 0);
    //后缀和
    fd(i, m, 1) suffix[i] = suffix[i+1] + (a[i].second == 1 ? 1 : 0);

    //yi去重标记
    int pos = 1;
    fp(i, 1, m) {
        if (a[i].first == a[i-1].first) {
            p[i] = pos;
        }
        else p[i] = (pos = i);
    }

    int mx = 0, cur = 0, ans = 0;
    fp(i, 1, m) {
        cur = prefix[p[i]-1]+suffix[p[i]];
        if (cur >= mx) {
            mx = cur; ans = a[i].first;
        }
    }

    cout << ans;


    _getch();
    return 0;
}
//---------------------------前缀和与后缀和__时间复杂度为O(n)-------------------------

// ---------------------------------暴力__TLE---------------------------------------
// using namespace std;
// const int maxm =1e5+5;
// int m;
// struct node {
//     int y, res;
// } stu[maxm];

// int cnt = 0, flag;
// struct node2 {
//     int y2, num;
// } tta[maxm];    

// bool cmp(node2 a, node2 b) {
//     if (a.num > b.num) return true;
//     else if (a.num == b.num && a.y2 >= b.y2) return true;
//     else return false;
// }

// int main(void) {
//     cin >> m;
//     fp(i, 1, m) {
//         cin >> stu[i].y >> stu[i].res;
//         flag = 1;
//         fp (j, 1, cnt) if (tta[j].y2 == stu[i].y) flag = 0;
//         if (flag) tta[++cnt].y2 = stu[i].y;
//     }
//     fp(j, 1, cnt) {
//         fp(i, 1, m) {
//             if (stu[i].y >= tta[j].y2 && stu[i].res == 1) tta[j].num++;
//             if (stu[i].y < tta[j].y2 && stu[i].res == 0) tta[j].num++;
//         }
//     }

//     sort(tta+1, tta+1+m, cmp);
//     cout << tta[1].y2;


//     _getch();
//     return 0;
// }
// ---------------------------------暴力__TLE---------------------------------------

