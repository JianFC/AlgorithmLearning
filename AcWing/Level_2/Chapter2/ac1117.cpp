#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1117. 单词接龙

const int N = 22;

int n;
string word[N];     //存储所有单词
int g[N][N];    //g[a][b]代表a在前，b在后，且a的后缀和b的前缀重合的最小长度
int used[N];        //used[i]代表第i个单词使用了几次
int ans;        //存储最优解

void dfs(string dragon, int last) {  //last存储了扩展前使用了哪个单词
    ans = max((int)dragon.size(), ans);     //更新全局最优值
    
    used[last] ++;      //更新used
    for (int i = 0; i < n; i ++)    //根据g数组进行状态扩展
        if (g[last][i] && used[i] < 2)    //last, i之间g值大于0，可以拼接
            dfs(dragon + word[i].substr(g[last][i]), i);    //拼接dragon，继续搜索
    
    used[last] --;      //外部搜索，恢复现场
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> word[i];
    char start;     //开头字母
    cin >> start;
    
    //建立邻接矩阵
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++) {
            string a = word[i], b = word[j];
            for (int k = 1; k < min(a.size(), b.size()); k ++)  //找到a和b重合的最小长度
                if (a.substr(a.size() - k, k) == b.substr(0, k)) {  //找到了a后缀和b前缀相同的最小的k
                    g[i][j] = k;
                    break;  //注意break掉
                }
        }
    
    //从所有以start开始的单词进行爆搜，找出最长值    
    for (int i = 0; i < n; i ++)
        if (word[i][0] == start)
            dfs(word[i], i);    //传入当前使用的单词的下标，用于记录其使用了多少次
    
    cout << ans;

    return 0;
}