#include <iostream>

using namespace std;

const int N = 1000010;

int n, k;
int a[N];
int q[N], hh, tt = -1;  //q单调队列，队列中存储的是数据的下标

int main(void) {    //AcWing 154. 滑动窗口
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {   //从前往后遍历每一个位置
        //判断对头是否已经滑出窗口，每次只移动一个位置，所以可以用if，不用while
        if (hh <= tt && i - k + 1 > q[hh]) hh++;    //队列不空 且 队头q[hh] < i - k + 1，即已经滑出窗口
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;  //保证单调性，注意此处队尾出队
        q[++tt] = i;    //将当前数插入单调队列，注意位置

        if (i - k + 1 >= 0) printf("%d ", a[q[hh]]);    //当窗口中有k个数时，输出最小值
    }

    puts("");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;

        if (i - k + 1 >= 0) printf("%d ", a[q[hh]]);    //输出最大值
    }

    return 0;
}