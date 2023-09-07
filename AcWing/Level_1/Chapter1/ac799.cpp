#include <iostream>

using namespace std;

const int N = 100010;

int n;
int a[N], s[N];     //S[N]数组当哈希表使用，s[a[i]]存储a[i]出现的次数

int main(void) {    //AcWing 799. 最长连续不重复子序列
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int res = 0;
    for (int i = 0, j = 0; i < n; i++) {    //i枚举终点，j枚举i往左最远能到的位置，j具有单调性，只能向后移动
        s[a[i]]++;

        while (j <= i && s[a[i]] > 1) {
            s[a[j]]--;
            j++;
        }

        res = max(res, i - j + 1);
    }

    cout << res;

    return 0;
}