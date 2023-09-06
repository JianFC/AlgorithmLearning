#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int t[N];

int main(void) {    //AcWing 913. 排队打水
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &t[i]);

    sort(t, t + n);   //将打水时间从小到大排序

    LL res = 0;

    for (int i = 0; i < n; i++) res += t[i] * (n - i - 1);

    cout << res << endl;

    return 0;
}
