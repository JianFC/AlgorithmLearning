#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1129. 热浪

const int N = 2510, M = 6200 * 2 + 10;      //无向图

int n, m, S, T;     //S和T分别代表起点和终点
int h[N], e[M], w[M], ne[M], idx;       //邻接表存图
int dist[N], q[N];   //dist存储起点到每个点的最短距离，q为spfa用到的循环队列
bool st[N];     //spfa判断每个元素是否再队列中

void add(int a, int b, int c) {     //建边函数
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void spfa() {       //跑一遍spfa，平均时间复杂度O(m)
    memset(dist, 0x3f, sizeof dist);    //首先初始化dist数组
    dist[S] = 0;    //初始化起点的距离
    
    int hh = 0, tt = 1;     //定义循环队列，队列初始中有起点，tt = 1开始，其插入元素为q[tt ++] = x
    q[0] = S, st[S] = true;     //初始时将起点加入队列
    
    while (hh != tt) {  //循环队列判空条件
        int t = q[hh ++];       //取队头
        if (hh == N) hh = 0;    //hh走到队尾，更新队头指针
        st[t] = false;      //t出队
        
        for (int i = h[t]; ~i; i = ne[i]) {     //循环t点的所有出边
            int j = e[i];       //取出边的另一头节点
            
            if (dist[j] > dist[t] + w[i]) {     //j点的最短距离可以被更新
                dist[j] = dist[t] + w[i];   //更新到j点的最短距离
                
                if (!st[j]) {   //点j没有在队列中，加入队列，队列存储所有变小的节点
                    st[j] = true;   //更新st
                    q[tt ++] = j;   //j点入队，注意循环队列入队为q[tt ++] = x
                    if (tt == N) tt = 0;        //tt走到队尾，更细队尾指针
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> S >> T;    //读入数据
    
    memset(h, -1, sizeof h);    //开头初始化表头
    
    for (int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;     //输入规模不大，可以用cin
        add(a, b, c), add(b, a, c);     //无向图
    }
    
    spfa();     //数据保证一定有解
    
    cout << dist[T] << endl;        //输出答案
    
    return 0;
}