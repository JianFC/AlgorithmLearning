#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;         //AcWing 894. 拆分-Nim游戏

const int N = 110;

int f[N];   //记忆化搜索，f[i]存储sg[i]的值

//记忆化搜索sg[x]的值  
int sg(int x) {        
    if (f[x] != -1) return f[x];

    unordered_set<int> S;
    for (int i = 0; i < x; i ++) 
        for (int j = 0; j <= i; j ++)
            S.insert(sg(i) ^ sg(j));  //sg(i, j) = sg(i) ^ sg(j);

    for (int i = 0; ; i ++)
        if (!S.count(i))
            return f[x] = i;
}

int main(void) {
    int n;
    scanf("%d", &n);

    memset(f, -1, sizeof f);

    int res = 0;
    while (n --) {
        int x;
        scanf("%d", &x);
        res ^= sg(x);
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}