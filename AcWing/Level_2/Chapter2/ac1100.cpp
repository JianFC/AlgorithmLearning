#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1100. 抓住那头牛

const int N = 2e5 + 10;     //最远可能用到2 * 10^5

int n, k;
int q[N];       //BFS队列
int dist[N];    //存储每个点到起点的最短距离，并完成st的作用

int bfs() {
    memset(dist, -1, sizeof dist);  //初始化dist
    dist[n] = 0;    //初始化起点的距离，注意起点是n
    
    int hh = 0, tt = 0;     //初始时n点在队列中
    q[0] = n;
    
    while (hh <= tt) {
        int t = q[hh ++];   //取对头
        
        if (t == k) return dist[t];     //终点已经被搜到
        
        // + 1的情况
        if (t + 1 < N && dist[t + 1] == -1) {       //注意边界是N
            dist[t + 1] = dist[t] + 1;  //更新距离
            q[++ tt] = t + 1;   //t + 1入队
        } 
        // - 1的情况
        if (t - 1 >= 0 && dist[t - 1] == -1) {
            dist[t - 1] = dist[t] + 1;
            q[++ tt] = t - 1;   //t - 1入队
        }
        // * 2的情况
        if (t * 2 < N && dist[t * 2] == -1) {
            dist[t * 2] = dist[t] + 1;
            q[++ tt] = t * 2;   //t * 2入队
        }
    }
    
    return -1;  //没有找到终点，保证代码完整性
}

int main() {
    cin >> n >> k;
    
    cout << bfs() << endl;
    
    return 0;
}