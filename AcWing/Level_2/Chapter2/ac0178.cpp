#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;        //178. 第K短路

#define x first
#define y second

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;    //int 存储估价函数值+真实距离值,第二个PII存储{S到点i的真实距离，点i}

const int N = 1010, M = 20010;      //需要建正向图和反向图，边开两倍大小

int n, m, S, T, K;
int h[N], rh[N], e[M], w[M], ne[M], idx;        //h[N]表示正向图，rh[N]表示反向图
int dist[N];    //dist[i]记录T到i点的最短距离，估计函数值
bool st[N];     //反向Dijkstra算法使用，判断点最小值是否已经确定

void add(int h[], int a, int b, int c) {    //建边函数
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;  
}

void Dijkstra() {   //估价函数，从T开始反向做一遍Dijkstra算法
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    
    heap.push({0, T});      //T入队
    dist[T] = 0;    //更新T的距离
    
    while (heap.size()) {
        auto t = heap.top();    //取队头
        heap.pop();     //出队
        
        int ver = t.y;  //取出点
        if (st[ver]) continue;  //ver最小距离已经确定
        st[ver] = true;     //更新st数组
        
        for (int i = rh[ver]; ~i; i = ne[i]) {  //注意遍历反向图rh
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {   //扩展能够更新的点
                dist[j] = dist[ver] + w[i];     //更新距离
                heap.push({dist[j], j});    //入队
            }   
        }
    }
}

int astar() {   //A*算法
    if (dist[S] == 0x3f3f3f3f) return -1;   //S, T不连通
    
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;     //小根堆
    heap.push({dist[S], {0, S}});   //起点入堆
    
    int cnt = 0;    //记录终点出队的次数
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        
        int ver = t.y.y, distance = t.y.x;      //取出该点的信息
        if (ver == T) cnt ++;   //更新终点出队次数
        if (cnt == K) return distance;  //一定会在cnt第一次到达K时返回掉第K短路的distance
        
        for (int i = h[ver]; ~i; i = ne[i]) {   //扩展ver的所有邻边
            int j = e[i];
            if (dist[j] == 0x3f3f3f3f) continue;    //重要！该点不能到T，不需要入队，防止TLE
            heap.push({distance + w[i] + dist[j], {distance + w[i], j}});   //{d + f, {d, j}}
        }
    }
    
    return -1;      //没有找到第K短路
}

int main() {
    memset(h, -1, sizeof h);    //注意在加边之前初始化
    memset(rh, -1, sizeof rh); 
    
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < m; i ++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(h, a, b, c);    //正向图
        add(rh, b, a, c);   //反向图，用于求估价函数
    }
    scanf("%d%d%d", &S, &T, &K);
    if (S == T) K ++;   //当起点终点相同时，按题目要求忽略没有边的情况
    
    Dijkstra();     //Dijkstra充当估价函数
    
    printf("%d\n", astar());    //输出A*算法结果
    
    return 0;
}
