#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>

using namespace std;        //1107. 魔板

char g[2][4];   //存储魔板状态
unordered_map<string, int> dist;        //存储每个状态距离的哈希表，完成st功能
unordered_map<string, pair<char, string>> pre;      //存储每个状态由哪个状态转移而来和相应的操作
queue<string> q;    //BFS队列

//将字符串转换到数组上
void set(string state) {
    for (int i = 0; i < 4; i ++) g[0][i] = state[i];    //第一行
    for (int i = 3, j = 4; i >= 0; i --, j ++) g[1][i] = state[j];  //第二行
}

//将数组转换到字符串
string get() {
    string res;
    for (int i = 0; i < 4; i ++) res += g[0][i];     //第一行
    for (int i = 3; i >= 0; i --) res += g[1][i];   //第二行
    return res;     //返回结果
}

//操作A
string move0(string state) {
    set(state);     //转换为数组
    for (int i = 0; i < 4; i ++) swap(g[0][i], g[1][i]);    //上下两行交换
    return get();   //返回字符串状态
}

//操作B
string move1(string state) {
    set(state);
    
    char c0 = g[0][3], c1 = g[1][3];    //暂存最后一列
    for (int i = 3; i; i --)    
        for (int j = 0; j < 2; j ++)
            g[j][i] = g[j][i - 1];      //每列往后移
    g[0][0] = c0, g[1][0] = c1;   //更新第一列
    
    return get();
}

//操作C
string move2(string state) {
    set(state);
    
    char c = g[0][1];   //暂存左上角
    g[0][1] = g[1][1];  //左上角
    g[1][1] = g[1][2];  //左下角
    g[1][2] = g[0][2];  //右下角
    g[0][2] = c;        //右上角
    
    return get();
}

//BFS搜索答案
void bfs(string start, string end) {
    if (start == end) return;   //特判起点
    
    q.push(start);      //起点入队
    dist[start] = 0;    //更新起点距离
    
    while (q.size()) {  //队列不空
        auto t = q.front();     //取队头
        q.pop();        //队头出队
        
        string m[3];   //存储3种转移操作后的状态
        m[0] = move0(t);    //操作A
        m[1] = move1(t);    //操作B
        m[2] = move2(t);    //操作C
        
        for (int i = 0; i < 3; i ++) {  //遍历能扩展到的状态
            string s = m[i];
            if (dist.count(s)) continue;    //已经被搜过
            
            dist[s] = dist[t] + 1;      //更新dist
            pre[s] = {char(i + 'A'), t};      //更新pre
            if (s == end) return;       //找到终点
            q.push(s);      //否则入队
        }
    }
} 

int main() {
    string start, end;      //初始状态和目标状态
    int x;
    for (int i = 0; i < 8; i ++) {
        cin >> x;
        end += x + '0';      //将输入转换为字符串状态
    }
    
    for (int i = 0; i < 8; i ++) start += i + '1';      //转换为字符串
    
    bfs(start, end);        //BFS搜索
    
    cout << dist[end] << endl;      //输出终点答案
    
    string res;     //存储转移路径操作
    while (end != start) {
        res += pre[end].first;  //存储操作
        end = pre[end].second;  //更新end
    }
    
    reverse(res.begin(), res.end());    //逆序保证起点 -> 终点
    
    if (res.size()) cout << res << endl;    //当操作数 > 0时才输出
    
    return 0;
}