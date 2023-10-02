#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;         //AcWing 861. 二分图的最大匹配

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];   //match[i]表示当前右半部中的点i匹配的左半部点
bool st[N];     //st[i]表示右半部点i是否已被某个特定的左半部点考虑过

void add(int a, int b) {   
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {   //该妹子x男生没有考虑过
            st[j] = true;

            if (match[j] == 0 || find(match[j])) {  //该妹子没有匹配男生，或者匹配的男生可以找到下家
                match[j] = x;   //更新匹配
                return true;    //返回答案
            }
        }
    }

    return false;
}

int main(void) {
    scanf("%d%d%d", &n1, &n2, &m);

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);  //只需存储从左向右的边
    }

    int res = 0;
    for (int i = 1; i <= n1; i ++) {     //从前往后考虑每个男生
        memset(st, false, sizeof st);   //对于该男生，所有妹子都没有考虑过，清空状态
        if (find(i)) res++;
    }

    cout << res;

    return 0;
}