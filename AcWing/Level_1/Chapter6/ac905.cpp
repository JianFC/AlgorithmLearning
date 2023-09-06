#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
struct Range {
    int l, r;

    bool operator< (const Range &W) const {
        return r < W.r;
    }
} range[N];

int main(void) {    //AcWing 905. 区间选点
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        range[i] = {a, b};
    }

    sort(range, range + n);   //按照区间右端点排序

    int res = 0, ed = -2e9; //最开始没有选择区间,ed初始化为负无穷

    //从前往后依次遍历每个区间
    for (int i = 0; i < n; i++) 
        if (range[i].l > ed) {
            res++;  //答案增加
            ed = range[i].r;    //更新ed
        }

    cout << res << endl;

    return 0;
}
