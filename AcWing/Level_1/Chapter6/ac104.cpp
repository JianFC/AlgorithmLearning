#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int a[N];

int main(void) {    //AcWing 104. 货仓选址
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    sort(a, a + n);   //从小到大排序，用于求出中位数

    LL res = 0;

    for (int i = 0; i < n; i++) res += abs(a[i] - a[(n - 1) / 2]);

    cout << res << endl;

    return 0;
} 
