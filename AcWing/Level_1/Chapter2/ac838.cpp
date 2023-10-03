#include <iostream>
#include <algorithm>

using namespace std;        //AcWing 838. 堆排序

const int N = 100010;

int n, m;
int h[N], cnt;      //h表示堆，cnt表示当前堆存了多少元素

//down操作，时间复杂度O(log(cnt))
void down(int u) {      
    int t = u;      //t记录u和u的左右儿子，共三个点中的最小值的编号
    if (2 * u <= cnt && h[2 * u] < h[t]) t = 2 * u;     //左儿子存在，且更小
    if (2 * u + 1 <= cnt && h[2 * u + 1] < h[t]) t = 2 * u + 1;     //右儿子存在，且更小
    if (t != u) {   //t发生了变化
        swap(h[t], h[u]);   //交换
        down(t);        //继续down(t)
    }
}

void up(int u) {    
    while (u / 2 && h[u / 2] > h[u]) {  //u的父节点存在，且父节点的值更大，迭代形式
        swap(h[u / 2], h[u]);   //u节点上移
        u >>= 1;    //u走到父节点位置，继续迭代
    }
}

int main(void) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) scanf("%d", &h[i]);
    cnt = n;

    //O(n)时间完成建堆
    for (int i = n / 2; i; i --) down(i);

    while (m--) {
        printf("%d ", h[1]);
        h[1] = h[cnt], cnt --;
        down(1);
    }

    return 0;
}