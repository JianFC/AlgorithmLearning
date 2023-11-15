#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //170. 加成序列

const int N = 110;

int n;
int path[N];    //path存储了加成序列

bool dfs(int u, int depth) {    //u表示当前搜到的层数，depth表示迭代加深的最大层数
    if (u > depth) return false;    //超出搜索范围
    if (path[u - 1] == n) return true;      //搜到了解，直接返回
    
    bool st[N] = {0};   //定义一个st数组，排除等效冗余，剪枝
    for (int i = u - 1; ~i; i --)   //从大到小枚举，枚举第一个数
        for (int j = i; ~j; j --) {   //枚举第二个数，规定第二个数小于等于第一个数，枚举组合数
            int s = path[i] + path[j];  //两数之和
            
            if (s > n || s <= path[u - 1] || st[s]) continue;   //越界，单调，没用过
            
            st[s] = true;   //更新st数组，剪枝使用，不是现场，不用恢复
            path[u] = s;    //更新path，同样不用恢复现场
            if (dfs(u + 1, depth)) return true;     //找到了答案
        }
    
    return false;       //没有找到答案
}

int main() {
    path[0] = 1;    //加成序列第一个数一定时1
    while (cin >> n, n) {
        int depth = 1;      //迭代加深初始层数为1
        while (!dfs(1, depth)) depth ++;    //从第一层开始搜，每次dfs最大层数深度为depth，直到搜到答案
        
        for (int i = 0; i < depth; i ++) cout << path[i] << " ";    //输出答案
        cout << endl;
    }
    
    return 0;
}