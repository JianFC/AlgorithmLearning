#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n;
struct Range {
    int l, r;

    bool operator< (const Range &W) const {
        return l < W.l;
    }
} range[N];

int main(void) {    //AcWing 906. 区间分组
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        range[i] = {a, b};
    }

    sort(range, range + n);

    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i++) 
        //若前面所有组最小的右端点最大值都大于等于该区间左端点，则新开一组
        if (heap.empty() || heap.top() >= range[i].l) heap.push(range[i].r);
        else {
            //若最小值<该区间左端点，则可将该区间合并到这一组中
            heap.pop();
            heap.push(range[i].r);
        }

    printf("%d\n", heap.size());

    return 0;
}
