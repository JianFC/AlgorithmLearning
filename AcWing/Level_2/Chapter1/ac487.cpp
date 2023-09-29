#include <iostream>
#include <algorithm>
#include <vector>

#define v first    //便于简化代码
#define w second 

using namespace std;        //487. 金明的预算方案

typedef pair<int, int> PII;

const int N = 70, M = 32010;

int n, m;
PII master[N];      //master[i]表示第i个主件的信息
vector<PII> servant[N];     //servant[i]表示第i个主件的附件
int f[M];   //f[i, j]表示从前i组物品中选，总体积不超过m的选法的最大价值，优化掉第一维

int main() {
    cin >> m >> n;
    
    for (int i = 1; i <= n; i ++) {
        int v, p, q;
        cin >> v >> p >> q;
        if (!q) master[i] = {v, v * p};     //主件，存储主件的价格和价值
        else servant[q].push_back({v, v * p});  //存储和主件相关的附件的信息
    }
    
    //分组背包求解
    for (int i = 1; i <= n; i ++) 
        if (master[i].v) {     //选出主件 && 只考虑价值大于0的主件
            for (int j = m; j >= 0; j --) {     //优化掉维度之后，从大到小枚举体积
                auto& sv = servant[i];  //简化代码
               
                for (int k = 0; k < 1 << sv.size(); k ++) {     //附件最多有两个，二进制枚举每个物品组内的附件决策
                    int v = master[i].v, w = master[i].w;   //初始时赋予v，w主件的体积和价值
                            
                    for (int u = 0; u < sv.size(); u ++)    //枚举每一位是什么
                        if (k >> u & 1) {   //该附件选
                            v += sv[u].v;   //更新体积
                            w += sv[u].w;   //更新价值
                        }
                    
                    if (j >= v) f[j] = max(f[j], f[j - v] + w);     //当容量够大时，更新f[j]
                }
            }
        }
        
    
    cout << f[m] << endl;   //输出答案
    
    return 0;
}
