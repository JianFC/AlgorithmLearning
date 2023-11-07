#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>

using namespace std;        //179. 八数码

#define x first
#define y second

typedef pair<int, string> PIS;      //x存距离，y存状态

int f(string state) {   //估价函数
    int d = 0;      //存储当前状态中每个数与其目标位置的曼哈顿距离之和
    for (int i = 0; i < state.size(); i ++)     //i是state[i]的当前位置
        if (state[i] != 'x') {
            int t = state[i] - '1';     //t是state[i]的目标位置
            d += abs(t / 3 - i / 3) + abs(t % 3 - i % 3);   //曼哈顿距离之和
        }
    
    return d;
}

void bfs(string start) {        //A*BFS搜索
    unordered_map<string, pair<char, string>> prev;     //存储状态的转移过程
    unordered_map<string, int> dist;        //状态距离哈希表，完成st功能
    priority_queue<PIS, vector<PIS>, greater<PIS>> heap;    //定义小根堆，依据第一个关键字排序
    
    heap.push({f(start), start});   //初始状态入队,{d + f, state}, 此处d == 0
    dist[start] = 0;    //更新起点dist，起点没有prev，不用更新
    
    string end = "12345678x";
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};     //方向向量
    char op[] = "urdl";     //和方向向量对应的操作字符
    
    while (heap.size()) {
        auto t = heap.top();    //取队头
        heap.pop();     //队头元素出队
        
        string state = t.y;     //取出状态
        
        if (state == end) break;    //找到终点，其最小距离已经确定
        
        int x, y;   //找到'x'的坐标
        for (int i = 0; i < state.size(); i ++)
            if (state[i] == 'x') {
                x = i / 3, y = i % 3;   // x的坐标
            }
            
        string source = state;     //暂存t，便于恢复现场
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];   //扩展t
            if (a < 0 || a >= 3 || b < 0 || b >= 3) continue;   //越界
            
            state = source;     //恢复现场
            swap(state[x * 3 + y], state[a * 3 + b]);   //更新状态
            
            if (!dist.count(state) || dist[state] > dist[source] + 1) {     //状态需更新
                dist[state] = dist[source] + 1;     //更新距离
                prev[state] = {op[i], source};  //记录前驱节点
                heap.push({dist[state] + f(state), state});     //依据A*算法规则入队
            }
        }
    }
    
    string res;     //存储操作顺序
    while (end != start) {
        res += prev[end].x;     //操作步骤
        end = prev[end].y;      //前驱状态
    }
    
    reverse(res.begin(), res.end());    //反转res
    cout << res << endl;        //输出结果
}

int main() {
    string start, seq;
    char c;
    while (cin >> c) {
        start += c;     //start保存完整字符串
        if (c != 'x') seq += c;     //seq不存x，用于计算逆序对
    }
    
    int cnt = 0;    //计算逆序对
    for (int i = 0; i < 8; i ++)
        for (int j = i + 1; j < 8; j ++)
            if (seq[i] > seq[j]) cnt ++;
    
    if (cnt & 1) puts("unsolvable");        //seq逆序对为奇数时，无解
    else bfs(start);
    
    return 0;
}