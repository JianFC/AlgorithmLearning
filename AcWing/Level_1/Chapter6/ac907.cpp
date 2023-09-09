#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
struct Range {
    int l, r;

    bool operator< (const Range &W) const {
        return l < W.l;
    }
} range[N];

int main(void) {    //AcWing 907. 区间覆盖
    int st, ed;
    scanf("%d%d", &st, &ed);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        range[i] = {a, b};
    }

    sort(range, range + n);   //按照左端点排序

    int res = 0;
    bool flag = false;
    //双指针从i开始从前往后找到能覆盖start且右端点最大的值
    for (int i = 0; i < n; i++) {
        int j = i, r = -2e9;    //注意j从i开始
        while (j < n && range[j].l <= st) {
            r = max(range[j].r, r);
            j++;
        }

        if (r < st) break;  //一定不能覆盖区间

        res++;
        if (r >= ed) {  //已经覆盖区间
            flag = true;
            break;
        }

        st = r;
        i = j - 1;    //更新i
    }

    if (flag) printf("%d\n", res);
    else puts("-1");

    return 0;
} 