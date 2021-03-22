#include <iostream>
#include <algorithm>
#include <cstdio>
#include <conio.h>
typedef unsigned long long ll;  //注意数据范围！

using namespace std;
ll n;
ll res = 0;

//注意思维方法，一个交点确定一组唯一的两条对角线，
//两条对角线确认一个唯一的四边形，所以原问题转换为求n多边形中最多可以划分出多少个不重复的四边形
int main(void) {
    cin >> n;
    res = n*(n-1)/2*(n-2)/3*(n-3)/4;    //n*(n-1)*(n-2)*(n-3)/24进行前部分乘积运算时，
                                        //结果超出unsigned long long 范围，所以需要把除操作分摊到每个乘积运算之后，
                                        //从而防止中间结果溢出
    cout << res;

    _getch();
    return 0;
}

// #include <iostream>
// #include <cstdio>
// #include <conio.h>
// using namespace std;
// unsigned long long n,ans;
// int main()
// {
//     scanf("%lld",&n);
//     ans=n * (n-1) / 2 * (n-2) / 3 * (n-3) / 4;
//     printf("%lld\n",ans);
//     _getch();
//     return 0;
    
// }