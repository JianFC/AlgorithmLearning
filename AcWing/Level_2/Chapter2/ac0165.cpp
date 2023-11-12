#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //165. 小猫爬山

const int N = 20;

int n, m;   //m表示每辆车承重上限
int w[N];   //每只小猫重量
int sum[N];     //sum[i]表示第i辆车已经装的小猫的重量总和
int ans = N;    //存储全局最小值，最坏情况每只小猫一辆车

void dfs(int u, int k) {    //u表示当前处理到了第几只小猫，k表示已有的车的数量
    if (k >= ans) return ;      //最优性剪枝
    if (u == n) {
        ans = k;    //更新全局最小值
        return ;
    }
    
    //1. 枚举u放到哪辆车上
    for (int i = 0; i < k; i ++)
        if (sum[i] + w[u] <= m) {   //可行性剪枝
            sum[i] += w[u];     //更新sum[i]
            dfs(u + 1, k);      //继续搜索
            
            sum[i] -= w[u];     //外部搜索恢复现场
        }
    
    //2. 新开一辆车
    sum[k] = w[u];  //新开第k辆车
    dfs(u + 1, k + 1);      //继续搜索，不要写成k ++
    sum[k] = 0;     //恢复现场
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> w[i];   //输入数据
    
    //优化搜索顺序
    sort(w, w + n);
    reverse(w, w + n);  //将小猫重量从大到小排序
    
    dfs(0, 0);      //从第0只小猫开始搜，当前已经开了0辆车
    
    cout << ans << endl;
    
    return 0;
}