#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N];   //f[i][j]降去第一维
            //从1~i个物品中选，总体积恰好是j的选法集合中元素的数量

int main(void) {    //AcWing 900. 整数划分 完全背包解法
    scanf("%d", &n);

    f[0] = 1;   //当容量为0时，只有一种选法即全都不选，

    //初始时，当j!=0时，f[j]=0，在没有选任何数的情况下不可能装满j

    //类似完全背包求解
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)    //注意循环起点位置
            f[j] = (f[j] + f[j - i]) % mod;     //f[i][j] = f[i-1][j]+f[i][j-i];

    cout << f[n] << endl;

    return 0;
}