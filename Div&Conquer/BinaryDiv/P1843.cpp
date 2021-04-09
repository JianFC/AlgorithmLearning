#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 5e5+10;
int arr[maxn] = {0};
int n, a, b;
int low, high, mid;

inline bool judge(int x){
    int tot = 0;    //记录总共需要使用烘干机多少秒
    //int temp;
    fp(i, 1, n) {
        if (arr[i]-a*x<=0) continue;    //第i件衣物能自然干燥
        else {
            tot += ceil((float)(arr[i] - a*x)/b);   //向上取整
            if (tot > x) return false;  //答案不合法
        }
    }

    return tot>x ? false:true;
}

int main(void){
    cin >> n >> a >> b;
    fp(i, 1, n) cin >> arr[i];
    low = 1; high = 5e5+10; 

    while(low <= high) {
        mid = (low+high)>>1;
        if(judge(mid)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }    
    }

    cout << low;    //注意输出为low，理解：当low=high时进行模拟推导

    _getch();
    return 0;
}