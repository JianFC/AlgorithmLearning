#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;

int n;
int q[N];
int up[N], down[N]; //up和down数组分别代表上升和下降子序列的g数组
int ans;    //记录全局最小值

//u代表当前处理到了第u个点，su表示当前上升子序列的数量，sd表示当前下降子序列的数量
void dfs(int u, int su, int sd) {
    if (su + sd >= ans) return;    //剪枝，ans不会被更新，注意等号
    if (u == n) {       ////找到一种新方案，此处ans<=su+sd
        ans = su + sd;
        return;
    }

    //分情况讨论
    //情况1：放入上升子序列
    int k = 0;
    while (k < su && up[k] >= q[u]) k ++;
    int t = up[k];  //恢复现场用
    up[k] =  q[u];
    if (k < su) dfs(u + 1, su, sd);   //未创建新序列
    else dfs(u + 1, su + 1, sd);    //创建新序列
    up[k] = t;  //恢复现场

    //情况2：放入下降子序列
    k = 0;
    while (k < sd && down[k] <= q[u]) k ++;
    t = down[k];
    down[k] = q[u];
    if (k < sd) dfs(u + 1, su, sd);
    else dfs(u + 1, su, sd + 1);
    down[k] = t;
}

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; i ++) cin >> q[i];

        ans = n;    //初始化ans为最大值
        dfs(0, 0, 0);

        cout << ans << endl;
    }

    return 0;
}