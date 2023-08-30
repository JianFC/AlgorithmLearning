#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 5010;

int n;
PII q[N];
int f[N];

int main() {    //1012. 友好城市
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &q[i].first, &q[i].second);
    
    sort(q, q+n);   //按南岸城市坐标从小到大排序
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++)
            if (q[i].second > q[j].second)
                f[i] = max(f[i], f[j] + 1);
        
        res = max(res, f[i]);
    }
    
    printf("%d", res);
    
    return 0;
}
