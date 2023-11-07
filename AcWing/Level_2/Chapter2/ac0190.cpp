#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>

using namespace std;        //190. 字串变换

const int N = 7;

int n;      //变换规则的个数
string A, B;    //起点和终点
string a[N], b[N];      //变换规则

int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db,
    string a[N], string b[N]) {     //da为q方向上的dist数组，db为另一个方向上的dist数组，q方向上的变换为a -> b
    
    int d = da[q.front()];      //暂存当前层的距离，便于后面完整扩展一层元素
    while (q.size() && da[q.front()] == d) {        //&& 保证只完整扩展一层
        auto t = q.front();     //取队头
        q.pop();        //队头出队
        
        for (int i = 0; i < n; i ++)    //遍历转换规则
            for (int j = 0; j < t.size(); j ++)     //遍历每一个转换起点
                if (t.substr(j, a[i].size()) == a[i]) {     //可以进行转换
                    string r = t.substr(0, j) + b[i] + t.substr(j + a[i].size());   //转换后的字符串
                    
                    if (db.count(r)) return da[t] + db[r] + 1;      //另一方向上的qb已经搜过该点，直接返回距离
                    if (da.count(r)) continue;      //该点已被qa搜过，直接跳过
                    da[r] = da[t] + 1;      //更新q方向上的dist数组
                    q.push(r);      //注意将r入队！
                }
    }
    
    return 11;  //返回大于10的数，表示没有搜到终点
}

int bfs() {     //双向BFS搜索
    if (A == B) return 0;       //不需要转换，特判样例

    queue<string> qa, qb;   //队列元素个数未知，直接用库，分别定义两个方向的队列
    unordered_map<string, int> da, db;      //两个方向上的dist哈希表，同时完成st功能
    
    qa.push(A), qb.push(B);     //起点入队
    da[A] = db[B] = 0;      //更新起点距离
    
    int step = 0;       //记录当前搜了多少层
    while (qa.size() && qb.size()) {    //如果一个队列空了，即终点不可达
        
        int t;      //暂存搜索结果
        if (qa.size() < qb.size()) t = extend(qa, da, db, a, b);    //扩展qa队列的一层，返回值为A到B的距离
        else t = extend(qb, db, da, b, a);      //qb的层数更少，扩展qb队列的一层，注意参数反向
        
        if (t <= 10) return t;      //A可以到B，且转换步数在10之内
        if (++ step == 10) return -1;    //已经转换了10次，没有找到解，直接返回-1，注意取==
    }
    
    return -1;      //没有找到解
}

int main() {
    cin >> A >> B;
    while (cin >> a[n] >> b[n]) n ++;   //输入规则和求出n
    
    int t = bfs();      //双向BFS
    if (t == -1) puts("NO ANSWER!");
    else cout << t << endl;
    
    return 0;
}