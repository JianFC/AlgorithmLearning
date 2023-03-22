#include <iostream>

using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N];   //f[i]表示以a[i]结尾的上升子序列的最大长度

int main(void) {    //AcWing 895. 最长上升子序列
    scanf("%d", &n);

    for (int i=1; i<=n; i++) scanf("%d", &a[i]);

    for (int i=1; i<=n; i++) {
        f[i] = 1;   //当只有一个数的情况，最少为1
        //枚举倒数第二个数
        for (int j=1; j<i; j++)
            if (a[j] < a[i]) f[i] = max(f[i], f[j]+1);
    }

    int res = 0;
    //搜索f[i]最大值
    for (int i=1; i<=n; i++) res = max(res, f[i]);

    cout << res << endl;

    return 0;
}
