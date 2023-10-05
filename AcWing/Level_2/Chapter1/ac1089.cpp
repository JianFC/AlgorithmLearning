#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;        //1089. 烽火传递

const int N = 200010, INF = 0x3f3f3f3f;

int n, m;
int w[N];   //w[i]表示每个烽火台的代价
int q[N];   //优化DP的单调队列
int f[N];   //f[i]表示1 - i中满足要求，且点燃第i个烽火台的所有方案的最小代价

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    
    int hh = 0, tt = 0;     //初始时f[0] = 0位于单调队列中
    for (int i = 1; i <= n; i ++) {
        //初始时队列中有元素，每次循环结束队列中也必有元素，且if最多移除一个元素，所以此处不用判断队列空否
        if (q[hh] < i - m) hh ++;   // 队头元素滑出窗口，不算i，队列最多有m个数
        f[i] = f[q[hh]] + w[i];     //更新f[i]
        while (hh <= tt && f[q[tt]] >= f[i]) tt --;     //维护单调队列性质
        q[++ tt] = i;       //i下标处元素如队
    }
    
    //枚举n - m + 1 - n中哪个烽火台被点燃，找到最小值
    int res = INF;
    for (int i = n - m + 1; i <= n; i ++) res = min(res, f[i]);
    
    printf("%d\n", res);
    
    return 0;
}