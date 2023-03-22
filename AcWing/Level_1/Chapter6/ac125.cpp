#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 50010;

int n;
PII cow[N];

int main(void) {    //AcWing 125. 耍杂技的牛
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        int w, s;
        scanf("%d%d", &w, &s);
        cow[i] = {w+s, w};
    }

    sort(cow, cow+n);   //按照w+s从小到大排序

    int res = -2e9, sum = 0;    //某头牛上面牛的重量之和
    for (int i=0; i<n; i++) {
        int w = cow[i].second, s = cow[i].first-w;
        res = max(res, sum-s);
        sum += w;
    } 

    cout << res << endl;

    return 0;
}
