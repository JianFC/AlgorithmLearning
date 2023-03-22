#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int n;
int a[N];
int q[N], len;   //q[i]表示在当前数前面，上升子序列长度为i的结尾最小值
                 //len表示在当前最大上升子序列的长度, 初始时长度为0
                 //也可以理解为当前q数组最后一个元素的位置

int main(void) {    //AcWing 896. 最长上升子序列 II，二分做法
    scanf("%d", &n);

    for (int i=0; i<n; i++) scanf("%d", &a[i]);

    q[0] = -2e9;    //设置哨兵，保证初始时q时单调序列，满足二分的性质

    //对每一个数分别考虑
    for (int i=0; i<n; i++) {
        int l = 0, r = len;     //二分左右边界

        while (l < r) {
            int mid = l+r+1>>1;
            if (q[mid] < a[i]) l = mid;
            else r = mid-1;
        }

        len = max(len, r+1);
        q[r+1] = a[i];  //由于二分性质，更新长度为r+1上升子序列结尾的最小值。
    }

    cout << len << endl;

    return 0;
}
