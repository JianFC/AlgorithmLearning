#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;            //168. 生日蛋糕

const int N = 30, INF = 0x3f3f3f3f;

int n, m;   //体积，层数
int minv[N], mins[N];   //minv[i]表示1~i层体积的最小值，mins[i]表示1~i层侧面表面积的最小值
int R[N], H[N];     //R[i]，H[i]分别表示第i层的半径和高度
int ans = INF;      //存储全局最小值

void dfs(int u, int v, int s) {
    if (v + minv[u] > n) return ;   //可行性剪枝
    if (s + mins[u] >= ans) return ;    //最优性剪枝
    if (s + 2 * (n - v) / R[u + 1] >= ans) return ;     //推出的剪枝条件
    
    if (!u) {   //所有层枚举完毕
        if (v == n) ans = s;    //找到目前最优方案,更新表面积
        return;     //注意return的位置！
    }
    
    for (int r = min(R[u + 1] - 1, (int)sqrt(n - v)); r >= u; r --)     //根据剪枝条件确定上下界
        for (int h = min(H[u + 1] - 1, (n - v) / r / r); h >= u; h --) {  //可行性剪枝条件
            int t = 0;  
            if (u == m) t = r * r;      ////当u == m时s需要加上最底层的圆面积
            R[u] = r, H[u] = h;     //更新R和H数组，恢复现场可省略
            dfs(u - 1, v + r * r * h, s + 2 * r * h + t);       //递归到第u - 1层继续处理
        }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {     //预处理minv和mins，不考虑pi
        minv[i] = minv[i - 1] + i * i * i;      //1~i层体积的最小值
        mins[i] = mins[i - 1] + 2 * i * i;      //1~i层侧面表面积的最小值
    }
    
    R[m + 1] = H[m + 1] = INF;  //第i层需要用到其下方i + 1层的信息，边界初始化两个哨兵
    
    //剪枝1：优化搜索顺序，自底向上搜索
    dfs(m, 0, 0);   //从最下方第m层开始搜索，已经搜索完的体积是0，搜索完的表面积是0
    
    if (ans == INF) ans = 0;    //没有找到合法解
    cout << ans << endl;    //输出全局最小值
    
    return 0;
}