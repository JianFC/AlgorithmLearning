#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;        //AcWing 338. 计数问题

//返回n中从l(高位)~r(低位)构成的数 
int get(vector<int> num, int l, int r) {        
    int res = 0;    // res 从0开始
    for (int i = l; i >= r; i--) res = res * 10 + num[i];
    return res;
}

//返回10^x
int power10(int x) {
    int res = 1;
    while (x--) res *= 10;
    return res;
}

//返回1~n中，x出现的次数
int count(int n, int x) {
    if (!n) return 0;   //当n=0，返回0

    //将n的每一位抠出来
    vector<int> num;
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }

    n = num.size();     //n更新为n的位数

    int res = 0;    //存储结果
     //从n的最高位开始统计x出现的次数，若x=0，则从次高位开始统计
    for (int i = n - 1 - !x; ~i; i --) {
        //情况1
        if (i < n - 1) {
            res += get(num, n - 1, i + 1) * power10(i);   //当x不为0，方案数为abc*10^i
            if (!x) res -= 1 * power10(i);    //当x=0时，为(abc-1)*10^i
        } 

        //情况2.2
        if (num[i] == x) res += get(num, i - 1, 0) + 1;
        //情况2.3
        else if (num[i] > x) res += power10(i);
    }

    return res;
}

int main(void) {
    int a, b;

    //输入技巧
    while (scanf("%d%d", &a, &b), a || b) {
        if (a > b) swap(a, b);

        for (int i = 0; i <= 9; i ++)
            cout << count(b, i) - count(a - 1, i) << " ";
        puts("");
    }

    return 0;
}