#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n;
vector<PII> segs;

void merge(vector<PII> &segs) {     //AcWing 803. 区间合并
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg: segs) {
        if (ed < seg.first) {
            if (ed != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg. second;
        }
        else ed = max(ed, seg.second);
    }

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}

int main(void) {
    scanf("%d", &n);

    while (n--) {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }

    merge(segs);

    cout << segs.size();

    return 0;
}