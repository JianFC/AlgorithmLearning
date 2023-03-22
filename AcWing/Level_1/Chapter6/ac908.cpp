#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
struct Range {
    int l, r;

    bool operator< (const Range &W) const  {
        return r < W.r;
    }
} range[N];

int main(void) {    //AcWing 908. 最大不相交区间数量
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        range[i] = {a, b};
    }

    sort(range, range+n);   //按区间右端点进行排序

    int res = 0, ed = -2e9;
    for (int i=0; i<n; i++)
        if (range[i].l > ed) {
            res++;
            ed = range[i].r;
        }

    cout << res << endl;

    return 0;
}
