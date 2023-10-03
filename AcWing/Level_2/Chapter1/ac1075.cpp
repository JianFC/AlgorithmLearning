#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1075. 数字转换

const int N = 50010, M = N;

int n;
int h[N], e[M], ne[M], idx;
int sum[N];     //sum[i]表示i的所有约数之和，采用筛法降低时间复杂度
bool st[N];     //st[i] = false记录森林中哪些节点是根节点
int ans;    //全局最长路径

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

//有向图，不用传father
int dfs(int u) {    //返回值是最高点是u的最远距离
    int d1 = 0, d2 = 0;     //初始化最大值和次大值
    
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        int d = dfs(j) + 1;     //注意边权是1
        
        if (d >= d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d; 
    }
    
    ans = max(ans, d1 + d2);    //更新全局最远距离
    
    return d1;      //返回最远距离
}

int main() {
    cin >> n;
    
    memset(h, -1, sizeof h);
    
    for (int i = 1; i <= n; i ++)   //筛法求sum数组
        for (int j = 2; j <= n / i; j ++)   //因为约数之和不含自己，所以j从2开始
            sum[i * j] += i;    //更新sum数组
        
    for (int i = 2; i <= n; i ++)   //注意从i = 2开始建边, 保证在正整数中变换
        if (i > sum[i]) {
            add(sum[i], i);     //将sum[i]作为父节点
            st[i] = true;   //i不是根节点
        }
    
    for (int i = 1; i <= n; i ++)
        if (!st[i])     //是根节点
            dfs(i); 
            
    cout << ans << endl;
    
    return 0;
}