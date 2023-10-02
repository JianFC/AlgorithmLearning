#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;    //AcWing 148. 合并果子

int main(void) {    
    int n;
    scanf("%d", &n);

    priority_queue<int, vector<int>, greater<int>> heap;    //维护小根堆

    for (int i = 0; i < n; i ++) {
        int x;
        scanf("%d", &x);
        heap.push(x);
    }

    int res = 0;    //存储答案
    while (heap.size() > 1) {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        res += a + b;
        heap.push(a + b);
    }

    printf("%d\n", res);

    return 0;
}