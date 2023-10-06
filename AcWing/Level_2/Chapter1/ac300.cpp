#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //300. 任务安排1

typedef long long LL;

const int N = 5010;

int n, s;
int sumt[N], sumc[N];   //sumt表示ti的前缀和，sumc表示ci的前缀和
LL f[N];   //f[i]表示所有将前i个任务处理完的所有分批方案的花费最小值

int main() {
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i ++) {
        int t, c;
        scanf("%d%d", &t, &c);
        sumt[i] = sumt[i - 1] + t;      //预处理前缀和
        sumc[i] = sumc[i - 1] + c;
    }
    
    memset(f, 0x3f, sizeof f);
    f[0] = 0;   //初始化
    
    for (int i = 1; i <= n; i ++)   //枚举i
        for (int j = 0; j < i; j ++)    //枚举j
            f[i] = min(f[i], f[j] + (LL)sumt[i] * (sumc[i] - sumc[j]) + (LL)s * (sumc[n] - sumc[j]));   //DP方程
    
    printf("%lld\n", f[n]);     //注意输出格式
    
    return 0;
}