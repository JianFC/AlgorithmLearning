#include <iostream>
#include <algorithm>

using namespace std;    //1024. 装箱问题

const int N = 20010;

int n, m;
int f[N];   //把体积同样视为价值，从而转换为01背包问题

int main() {
    cin >> m >> n;
    
    for (int i = 0; i < n; i ++) {
        int v;
        cin >> v;
        for (int j = m; j >= v; j --) f[j] = max(f[j], f[j - v] + v);
    }
    
    cout << m - f[m] << endl;   //剩余体积
    
    return 0;
}