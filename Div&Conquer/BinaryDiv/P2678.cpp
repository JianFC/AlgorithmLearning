#include <iostream>
#include <algorithm>
#include <cstdio>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 5e4+10;
int arr[maxn] = {0};
int l, n, m;
int low, high, mid;     //二分搜索三界限
int res;    //保存输出结果

//判断函数
inline bool judge(int x) {
    int tot = 0;
    int prerock = 0;    //上一块未被移走的岩石位置
    fp(i, 1, n) {
        if (arr[i] - arr[prerock] <= x) {   //注意如果最终答案输出low的取值的话，此处判断条件只能写成<=，而不能写成<，
                                            //模拟一个示例来理解此处的原因
            tot++;
            if (tot>m) return false;
        } else {
            prerock = i;
        }
    }   
    return tot > m ? false: true; 
}

int main(void){
    cin >> l >> n >> m;
    fp(i, 1, n) cin >> arr[i];
    arr[++n] = l;   //初始化距离数组
    low = 1, high = arr[n];

    while(low<=high) {
        mid = (low+high)>>1;
        if(judge(mid)) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }

    cout << low;

    _getch();
    return 0;
}