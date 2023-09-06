#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 110, M = 100010;  

int n, m;
int s[N], f[M];     //s[i]表示集合S中第i个数，f[i]记忆i的sg函数值

//记忆化搜索x的sg函数值
int sg(int x) {         //AcWing 893. 集合-Nim游戏
    if (f[x] != -1) return f[x];

    unordered_set<int> S;   //存储有向图中x当前能到的点的SG函数值集合
    for (int i = 0; i < m; i++) {
        int sum = s[i];
        if (x >= sum) S.insert(sg(x - sum));
    }

    //求出sg[x], 存储与记忆化数组f[x]中，避免重复搜索
    for (int i = 0; ; i++) 
        if (!S.count(i))
            return f[x] = i;
}

int main(void) {
    memset(f, -1, sizeof f);

    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", &s[i]);

    scanf("%d", &n);
    int res = 0;    //res记录每一堆石子SG函数值进行异或后的结果
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        res ^= sg(x);
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}