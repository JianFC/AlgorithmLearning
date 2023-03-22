//类约瑟夫问题
#include <iostream>
#include <algorithm>
#include <vector>
#include <conio.h>
#include <cstring>
#include <cstdio>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
int a[5] = {0};   //a[1-4]分别表示甲乙丙丁跳过的次数
int pos = 0;    //pos的值代表当前是第几个同学报数, pos = pos%4+1
int n;

//检查是否含7
inline bool check7(int num) {
    int flag = 1, remainder;
    while (num != 0) {
        remainder = num%10;
        num = num/10;
        if (remainder == 7) { flag = 0; break;}
    }
    return (flag == 0 ? true : false);    //含有数字7为真，不含数字7为假
}

//检查是否含7或者是7的倍数
inline bool check(int num) {
    if (num%7==0 || check7(num)) return false;  //不符合要求
    else return true;
}

int main(void) {
    cin >> n;

    int cnt = 1;    //计数
    while (n--) {
        if (!check(cnt)) { n++; a[pos%4+1]++; }
        pos++;  cnt++;
    }

    fp(i, 1, 4) cout << a[i] << endl;

    _getch();
    return 0;
}
