#include <iostream>
#include <algorithm>

using namespace std;    //1012. 友好城市

typedef pair<int, int> PII;

const int N = 5010;

int n;
PII q[N];       //存储友好城市的对应关系
int f[N];       //f为LIS的DP数组

int main() {    
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d%d", &q[i].first, &q[i].second);
    
    sort(q, q + n);   //按南岸城市坐标（第一个关键字）从小到大排序
    
    int res = 0;
    for (int i = 0; i < n; i ++) {      //LIS问题求解
        f[i] = 1;
        for (int j = 0; j < i; j ++)
            if (q[i].second > q[j].second)
                f[i] = max(f[i], f[j] + 1);
        
        res = max(res, f[i]);
    }
    
    printf("%d\n", res);
    
    return 0;
}
