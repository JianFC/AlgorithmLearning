#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;        //AcWing 1010. 拦截导弹

const int N = 1010;

int n;
int a[N];       //存储原序列
int f[N], g[N];     //f表示LIS问题的解，g存储当前所有已经开好的子序列的结尾的数，g序列一定单调递增

int main() {
    string line;
    getline(cin, line);
    stringstream ssin(line);    //注意读入方式，stingstream读入方式
    while (ssin >> a[n]) n ++;

    // while (cin >> a[n]) n ++;   //or不使用stringstream读入
    
    int res = 0;    //LIS求解
    for (int i = 0; i < n; i ++) {
        f[i] = 1;
        for (int j = 0; j < i; j ++)
            if (a[i] <= a[j]) 
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);       //记录全局最大值
    }
    
    cout << res << endl;
    
    //贪心求解第二问
    int cnt = 0;    //记录最长不上升子序列的数量
    for (int i = 0; i < n; i ++) {
        int k = 0;
        while (k < cnt && g[k] < a[i]) k ++;    //g单调递增，寻找第一个大于等于a[i]且结尾最小的序列
        g[k] = a[i];            //将a[i]插入对应的序列中（找到和没找到的情况，代码一致）
        if (k >= cnt) cnt ++;       //没有找到合法的序列，新开一些序列
    }
    
    cout << cnt;
    
    return 0;
}