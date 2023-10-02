#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;        //AcWing 1010. 拦截导弹

const int N = 1010;

int n;
int a[N];
int f[N], g[N];     //g[i]表示第i个最长不上升子序列结尾的值

int main() {
    string line;
    getline(cin, line);
    stringstream ssin(line);    //注意读入方式
    while (ssin >> a[n]) n ++;
    
    int res = 0;    //LIS求解
    for (int i = 0; i < n; i ++) {
        f[i] = 1;
        for (int j = 0; j < i; j ++)
            if (a[i] <= a[j]) 
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }
    
    cout << res << endl;
    
    int cnt = 0;    //记录最长不上升子序列的数量
    for (int i = 0; i < n; i ++) {
        int k = 0;
        while (k < cnt && g[k] < a[i]) k ++;    //寻找第一个大于等于a[i]且结尾最小的序列
        g[k] = a[i];
        if (k >= cnt) cnt ++;
    }
    
    cout << cnt;
    
    return 0;
}