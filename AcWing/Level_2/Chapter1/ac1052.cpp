#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;    //1052. 设计密码

const int N = 60, mod = 1e9 + 7;

int n, m;   //m表示模板串的长度
char str[N];    //存储模板串
int ne[N];  //kmp的next数组
int f[N][N];    //f[i][j]表示所有填到了密码的第i位，模板串匹配到了第j位的方案的数量

int main() {
    cin >> n >> str + 1;    //下标从1开始
    m = strlen(str + 1);    //计算模板串的长度
    
    //求next数组过程
    for (int i = 2, j = 0; i <= m; i ++) {
        while (j && str[i] != str[j + 1]) j = ne[j];    //j指针跳的过程
        if (str[i] == str[j + 1]) j ++;     //移到下一个位置
        ne[i] = j;  //更新ne[i];
    }
    
    f[0][0] = 1;    //初始化方案数
    for (int i = 0; i < n; i ++)    //从后往前递推
        for (int j = 0; j < m; j ++)        //不能跳到m，故j<m
            for (char k = 'a'; k <= 'z'; k ++) {    //枚举第i + 1位可能的字符，即对于每个j，枚举26条边
                int u = j;  //对j备份
                while (u && k != str[u + 1]) u = ne[u];     //看j最终跳到模板串的哪个位置
                if (k == str[u + 1]) u ++;  //更新u
                if (u < m) f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod; //当没有匹配模板串时，更新f[i + 1][u]
            }
            
    int res = 0;
    for (int i = 0; i < m; i ++) res = (res + f[n][i]) % mod;   //对所有位置求和，注意<m
    
    cout << res << endl;
    
    return 0;
}