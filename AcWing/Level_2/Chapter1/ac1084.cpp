#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;        //1084. 数字游戏 II

const int N = 15, M = 110;

int P;  //模的数
int f[N][10][M];    //f[i, j, k]表示最高位为j，一共有i位，且模p余数位k的数的集合

int mod(int x, int y) {
    return (x % y + y) % y;     //C++自带%函数，运算结果位负数时会返回负数，此处将其转为正数
}

void init() {
    memset(f, 0, sizeof f);
     
    for (int i = 0; i <= 9; i ++) f[1][i][i % P] ++;    //注意是++，不是= 1，多组数据注意清空
    
    for (int i = 2; i < N; i ++)    //枚举位数
        for (int j = 0; j <= 9; j ++)   //枚举最高位数
            for (int k = 0; k < P; k ++)    //枚举余数
                for (int x = 0; x <= 9; x ++)   //枚举i - 1位
                    f[i][j][k] += f[i - 1][x][mod(k - j, P)];   //注意是k - j
                    
}

int dp(int n) {
    if (!n) return 1;   //当n == 0时，有一个数
    
    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;      //将n的每一位拿出来
    
    int res = 0, last = 0;  //res记录答案，last存储前面所有位上数字之和
    for (int i = nums.size() - 1; i >= 0; i --) {
        int x = nums[i];    //取出x
        
        for (int j = 0; j < x; j ++)    //枚举节点左边部分
            res += f[i + 1][j][mod(-last, P)];      //题目要求 % P == 0，且前缀已经存储last，所以 -last % P == 0
            
        last += x;  //右边部分，继续向下
        
        if (!i && last % P == 0) res ++;    //当走到最后一层，且last % P == 0，最右侧分支也是一种答案 
    }
    
    return res;
}

int main() {
    int l, r;
    while (cin >> l >> r >> P) {
        init();
        
        cout << dp(r) - dp(l - 1) << endl;
    }
    
    return 0;
}