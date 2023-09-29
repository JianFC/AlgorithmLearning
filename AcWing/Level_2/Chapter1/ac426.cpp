#include <iostream>
#include <algorithm>

using namespace std;    //426. 开心的金明

const int N = 30010;

int n, m;
int f[N];   //01背包f数组

int main() {
    cin >> m >> n;
    
    for (int i = 0; i < n; i ++) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j --) f[j] = max(f[j], f[j - v] + v * w);   //01背包
    }
    
    cout << f[m] << endl;
    
    return 0;
}