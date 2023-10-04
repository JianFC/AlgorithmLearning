#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;        //1081. 度的数量

const int N = 35;   //转化为B进制的位数

int K, B;
int C[N][N];    //组合数

void init() {   //预处理组合数
    for (int i = 0; i < N; i ++)
        for (int j = 0; j <= i; j ++)
            if (!j) C[i][j] = 1;    //定义
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];   //递推公式
}

int dp(int n) {
    if (!n) return 0;   //当n == 0时
    
    vector<int> nums;   //将n的每一位抠出来
    while (n) nums.push_back(n % B), n /= B;    //将n转换为B进制数
    
    int res = 0, last = 0;      //res存储答案，last存储树上的前缀信息，本题存储已经凑了多少个1
    for (int i = nums.size() - 1; i >= 0; i --) {   //从最高位开始枚举，树的根节点开始处理
        int x = nums[i];    //拿出第i位
        
        if (x) {    //x >= 1
            res += C[i][K - last];  //每个节点左边的分支，情况1，填0
            if (x > 1) {
                //每个节点左边的分支，情况2，填1，后面还能填k - last - 1个1
                if (K - last - 1 >= 0) res += C[i][K - last - 1];      
                break;  //当x > 1时，右边分支不合法，break
            }
            else {  //x == 1
                last ++;    //没有情况2，节点右边分支为1，更新前缀信息，继续看下一位
                if (last > K) break;    //K个1已经填完，后续没有合法方案，break
            }
        }
        
        if (!i && last == K) res ++;    //最右侧分支的答案，当满足该条件时，所有k都在右侧分支里
                                        //并且没有对res进行跟新，当枚举到第0位时，加上最右侧分支的答案
                                        //即判断右侧分支上的树是不是合法的，合法则加1
    }
    
    return res;     //返回答案
}

int main() {
    init();     //初始化组合数
    
    int x, y;
    cin >> x >> y >> K >> B;
    
    cout << dp(y) - dp(x - 1) << endl;
    
    return 0;
}