#include <iostream>
#include <algorithm>

using namespace std;    //1022. 宠物小精灵之收服

const int N = 1010, M = 510;

int n, V1, V2;
int f[N][M];    //优化掉1维,f[i][j][k]表示只从前i个物品中选，v1不超过j，v2不超过k的选法的最大价值

int main() {
    cin >> V1 >> V2 >> n;
    
    for (int i = 0; i < n; i ++) {
        int v1, v2;
        cin >> v1 >> v2;
        for (int j = V1; j >= v1; j --)         //降维后从大到小循环
            for (int k = V2 - 1; k >= v2; k --)     //不能取到V2，体力值大于0
                f[j][k] = max(f[j][k], f[j - v1][k - v2] + 1);
    }
    
    cout << f[V1][V2 - 1] << " ";
    int k = V2 - 1;
    while (k > 0 && f[V1][k - 1] == f[V1][V2 - 1]) k --;    //注意循环条件k - 1
    cout << V2 - k << endl;     //输出剩余体力
    
    return 0;
}