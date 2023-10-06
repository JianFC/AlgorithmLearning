#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;    //734. 能量石

const int N = 10010;    //时间最大值，N * S

int n;
struct Stone {
    int s, e, l;
    
    bool operator< (const Stone & W) const {    //贪心时使用
        return s * W.l < W.s * l;
    }
} stone[N];

int f[N];   //01背包问题状态表示，体积定义为恰好是j，优化一维

int main() {
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++) {
        cin >> n;
        int m = 0;  //存储时间最大值
        
        for (int i = 0; i < n; i ++) {
            int s, e, l;
            cin >> s >> e >> l;
            stone[i] = {s, e, l};
            m += s;     //更新m，01背包问题时使用
        }
        
        sort(stone, stone + n);     //按照指定规则排序
        memset(f, -0x3f, sizeof f);     //定义为恰好时初始化
        f[0] = 0;
        
        for (int i = 0; i < n; i ++) {
            int s = stone[i].s, e = stone[i].e, l = stone[i].l;
            
            for (int j = m; j >= s; j --)   //从大到小循环
                f[j] = max(f[j], f[j - s] + e - (j - s) * l);    //e - (j - s) * l表示剩余的能量
        }
        
        int res = 0;    //搜一遍答案
        for (int i = 0; i <= m; i ++) res = max(res, f[i]);
        
        printf("Case #%d: %d\n", C, res);
    }
    
    return 0;
}