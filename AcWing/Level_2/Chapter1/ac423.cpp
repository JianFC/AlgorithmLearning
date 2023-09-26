#include <iostream>

using namespace std;

const int N = 1010;     //423. 采药

int n, m;
int f[N];   //01背包问题，降维

int main() {
    cin >> m >> n;
    
    for (int i = 0; i < n; i ++) {
        int v, w;
        cin >> v >> w;
        //01背包问题
        for (int j = m; j >= v; j --) f[j] = max(f[j], f[j - v] + w);
    }
    
    cout << f[m] << endl;
    
    return 0;
}