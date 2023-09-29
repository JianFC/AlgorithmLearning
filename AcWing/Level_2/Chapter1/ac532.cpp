#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;    //532. 货币系统

const int N = 110, M = 26000;

int n, m;
int a[N];   //存储每个货币系统的货币
int f[M];   //完全背包，f[i]存储凑出i的方案数是否大于0

int main() {
    int T;
    cin >> T;
    
    while (T --) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i ++) cin >> a[i];
    
        sort(a, a + n);     //对a数组排序
        memset(f, 0, sizeof f);     //清空上组数据结果
        int m = a[n - 1];   //每组数据最大的数
        
        f[0] = 1;   //初始化
        int res = 0;    //记录结果
        
        for (int i = 0; i < n; i ++) {  //从前往后考虑每个货币
            if (!f[a[i]]) res ++;   //a[i]不能被a[1] ~ a[i - 1]表示出来，必选
            
            for (int j = a[i]; j <= m; j ++)    //完全背包问题，看a[i]后面的数能否由a[1] - a[i]表示出来
                f[j] += f[j - a[i]];    //完全背包问题求方案数
        }
        
        cout << res << endl;    //输出结果
    }
    
    return 0;
}