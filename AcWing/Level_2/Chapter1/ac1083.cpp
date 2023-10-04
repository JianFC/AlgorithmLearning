#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;        //1083. Windy数

const int N = 15;   //最高位数

int f[N][N];    //f[i, j]表示最高位是j，且一共有i位的windy数的数量

void init() {
    for (int i = 0; i <= 9; i ++) f[1][i] = 1;  //初始化，注意从0开始，防止后面状态计算出错
    
    for (int i = 2; i < N; i ++)    //枚举位数
        for (int j = 0; j <= 9; j ++)   //最高位数
            for (int k = 0; k <= 9; k ++)
                if (abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];     //递推方程
}

int dp(int n) {
    if (!n) return 0;   //特判0，假设0不算windy数，置1出错
    
    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;
    
    int res = 0, last = -2;     //last需初始化为和0 - 9任意一个数的差的绝对值 >= 2的数
    for (int i = nums.size() - 1; i >= 0; i --) {
        int x = nums[i];
        
        for (int j = i == nums.size() - 1; j < x; j ++)     //trick：i = nums.size() - 1时从1开始，否则从0开始
            if (abs(j - last) >= 2)
                res += f[i + 1][j];     //注意有i + 1位
                
        
        if (abs(x - last) < 2) break;   //右边部分不存在
        last = x;   //更新last
        
        if (!i) res ++;     //走到最后一层，加上最右侧分支这一种合法答案
    }
    
    //特殊处理含有前导0的情况，因为上面把所有含前导0的情况都过滤掉了，例如00146，此处需加回来
    for (int i = 1; i <= nums.size() - 1; i ++)
        for (int j = 1; j <= 9; j ++)   //最高位可以是1 - 9
            res += f[i][j];     
    
    return res;
}

int main() {
    init();
    
    int l, r;
    cin >> l >> r;
    cout << dp(r) - dp(l - 1) << endl;
    
    return 0;
}