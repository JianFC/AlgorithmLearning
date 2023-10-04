#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;        //1082. 数字游戏

const int N = 15;   //int范围20亿，10位数，开15

int f[N][N];    //f[i, j]表示最高位是j，且一共有i位的不降数的数量

void init() {
    for (int i = 0; i <= 9; i ++) f[1][i] = 1;  //初始化
    
    for (int i = 2; i < N; i ++)    //枚举位数
        for (int j = 0; j <= 9; j ++)
            for (int k = j; k <= 9; k ++)
                f[i][j] += f[i - 1][k];     //递推关系
}   

int dp(int n) {
    if (!n) return 1;   //当n = 0时，1种方案，同时特判掉后面nums中的边界情况
    
    vector<int> nums;   //存储n中的每一位数
    while (n) nums.push_back(n % 10), n /= 10;
    
    int res = 0, last = 0;  //res存储结果，last保存前缀信息，具体位上一位的值，初始为0，前导0不影响本体
    for (int i = nums.size() - 1; i >= 0; i --) {
        int x = nums[i];
        
        for (int j = last; j < x; j ++) //枚举左边部分情况，共i + 1位，最高位是j
            res += f[i + 1][j];     
        
        if (x < last) break;    //没有右边部分情况，break
        last = x;   //更新last，传递下去
        
        if (!i) res ++;     //成功到达最右小角部分，n本身是一个合法解，res ++
    }
    
    return res;
}

int main() {
    init();
    
    int l, r;
    while (cin >> l >> r) cout << dp(r) - dp(l - 1) << endl;
    
    return 0;
}