#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1090. 绿色通道

const int N = 50010;

int n, t;
int w[N];   //w[i]表示每道题的时间
int f[N], q[N];     //f[i]表示1 - i中没有limit + 1个空隙，且第i题做的所有方案的最小时间

bool check(int limit) {
    f[0] = 0;   //初始入队元素
    
    int hh = 0, tt = 0;     //初始队列中有f[0]
    for (int i = 1; i <= n; i ++) {
        if (q[hh] < i - limit - 1) hh ++;   //注意相比烽火传递，不算i，队列中最多可以有limit + 1个元素
        f[i] = f[q[hh]] + w[i];     //状态转移方程
        while (hh <= tt && f[q[tt]] >= f[i]) tt --;     //维护单调队列
        q[++ tt] = i;   //入队
    }
    
    for (int i = n - limit; i <= n; i ++)   //注意起始点为 n - (limit + 1) + 1 = n - limti
        if (f[i] <= t)
            return true;    //该limit满足要求
    
    return false;   //limit不满足要求
}

int main() {
    cin >> n >> t;  //输入数据为5w，小于10w，可以用cin
    for (int i = 1; i <= n; i ++) cin >> w[i];
    
    int l = 0, r = n;
    while (l < r) {     //二分limit，右区间中答案
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    
    cout << l << endl;
    
    return 0;
}