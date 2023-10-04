#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;        //1085. 不要62

const int N = 15;

int f[N][10];   //f[i, j]表示最高位为j，且一共有i位的不含4或者62的数的数量

void init() {
    for (int i = 0; i <= 9; i ++)   //初始化第1位
        if (i != 4)     //不能含4
            f[1][i] = 1;
            
    for (int i = 2; i < N; i ++)
        for (int j = 0; j <= 9; j ++) {
            if (j == 4) continue;   //j == 4时continue
            for (int k = 0; k <= 9; k ++) {
                if (k == 4 || j == 6 && k == 2) continue;   //不含62
                f[i][j] += f[i - 1][k];     //递推方程
            }
        }
}

int dp(int n) {
    if (!n) return 1;   //当n == 0时，是一种合法方案
    
    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;
    
    int res = 0, last = 0;      //last保存上一位数字是什么，判断不能含62，初始为0
    for (int i = nums.size() - 1; i >= 0; i --) {
        int x = nums[i];
        
        for (int j = 0; j < x; j ++) {
            if (j == 4 || last == 6 && j == 2) continue;    //不合法
            res += f[i + 1][j];     //此时共i + 1位，最高位为j
        }
        
        if (x == 4 || last == 6 && x == 2) break;   //不存在右分支
        last = x;       //更新last
        
        if (!i) res ++;     //走到最后，最右侧分支是一种合法方案
    }
    
    return res;
}

int main() {
    init();
    
    int l, r;
    while (cin >> l >> r, l || r) {
        cout << dp(r) - dp(l - 1) << endl;
    }
    
    return 0;
}