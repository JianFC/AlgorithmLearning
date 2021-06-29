// #include <iostream>
// #include <cstring>
// #include <cstdio>
// #include <string.h>

// using namespace std;

// int main() {
//     char str[1000];
//     // gets(str);
//     cin >> str;
    
//     for (int i=0; str[i]; i++) {
//         int j=i;
//         while (j < int(strlen(str)) && str[j] != ' ') j++;
        
//         //这道问题的具体逻辑
//         for (int k=i; k<j; k++) cout << str[k];
//         cout << endl;
        
//         i = j;
//     }
    
//     return 0;
// }

//-----------------------------------------------------------------------------
//朴素做法：O（n^2）
// for (int i=0; i<n; i++)
//     for (int j=0; j<i; j++) {
//         if (check(i, j)) {
//             res = max(res, i-j+1);
//         }
//     }

//双指针算法O(n)
// for (int i=0, j=0; i<n; i++) {
//     while(j<i&&check(i, j)) j++;
//     res = max(res, i-j+1);
// }

// #include <iostream>

// using namespace std;

// const int maxn = 1e5+10;

// int a[maxn], s[maxn];        //s数组为动态计数器

// int main(void) {
//     int n; cin >> n;
//     int res;
//     for (int i=1; i<=n; i++) cin >> a[i];
    
        //双指针算法
//     for (int i=1, j=1; i<=n; i++) {
//         s[a[i]]++;
//         while (j<i && s[a[i]] > 1) {
//             s[a[j]]--;
//             j++;
//         }
        
//         res = max(res, i-j+1);
//     }
//     cout << res;
    
//     return 0;
// }

//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

// #include <iostream>

// using namespace std;

// int lowbit(int x) {
//     return x&-x;
// }

// int main() {
//     int n;
//     cin >> n;
//     int x;
//     while (n--) {
//         cin >> x;
//         int res = 0;
//         while(x) x -= lowbit(x), res++;
        
//         cout << res << " ";
//     }
    
//     return 0;
// }
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;
// typedef pair<int, int> pii;


// const int maxn = 3e5+10;

// int n, m;
// int a[maxn], s[maxn];
// vector<int> alls;
// vector<pii> add, query;

// int find(int x) {
//     int l = 0, r = alls.size()-1;
//     while(l<r) {
//         int mid = (l+r)>>1;
//         if (alls[mid]>=x) r = mid;
//         else l = mid+1;
//     }
//     return r+1;
// }

// vector<int>::iterator unique(vector<int> &a) {
//     int j = 0;
//     for (int i=0; i<a.size(); i++) {
//         if (!i || a[i]!=a[i-1])
//             a[j++] = a[i];
//     }
//     return a.begin()+j;
// }

// int main(void) {
//     cin >> n >> m;
//     for (int i=1; i<=n; i++) {
//         int x, c;
//         cin >> x >> c;
//         add.push_back({x, c});
//         alls.push_back(x);
//     }
    
//     for (int i=1; i<=m; i++) {
//         int l, r;
//         cin >> l >> r;
//         query.push_back({l, r});
        
//         alls.push_back(l);
//         alls.push_back(r);
//     }
    
//     sort(alls.begin(), alls.end());
//     // alls.erase(unique(alls.begin(), alls.end()), alls.end());
//     alls.erase(unique(alls), alls.end());
    
//     for (auto item: add) {
//         int x = find(item.first);
//         a[x] += item.second;
//     }
    
//     for (int i=1; i<=alls.size(); i++) s[i] = s[i-1] + a[i];
    
//     for (auto item: query) {
//         int l = find(item.first);
//         int r = find(item.second);
//         cout << s[r] - s[l-1] << endl;
//     }
    
    
    
    
    
//     return 0;
// }

//----------------------------------------------------------------------------

