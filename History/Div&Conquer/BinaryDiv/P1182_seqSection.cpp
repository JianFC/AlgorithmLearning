//二分法，最小距离最大化
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <conio.h> 
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1e6+10;
int arr[maxn] = {0};
int n, m;
int low = 0, high = 0, mid = 0;     //二分法三边界
int res = 0;

////模板函数，通过x的取值来判定在右区间搜索（true）还是左区间搜索（false）
inline bool judge(int x) { 
    int totm = 0;   //记录能够分段的段数，初始化为0
    int sum = 0;    //记录区间和
    fp(i, 1, n) {
        if (sum + arr[i] <= x) {
            sum += arr[i];  //更新区间和
        }
        else {
            totm++; //更新已经分段的段数 
            sum = arr[i];   //更新区间和为新一段的第一个元素值
            if (totm >= m) return true;
        }

        // if (sum + arr[i] > x) {
        //     totm++; //更新已经分段的段数 
        //     sum = arr[i];   //更新区间和为新一段的第一个元素值
        //     if (totm >= m) return true;
        // }
        // else {
        //     sum += arr[i];  //更新区间和
        // }
    }

    return totm>=m;
}

int main(void) {
    cin >> n >> m;
    fp(i, 1, n) {
        cin >> arr[i];
        low = max(low, arr[i]); //设定low初值
        high += arr[i]; //设定high初值
    }
    //区间和最大值的最小值一定位于区间[max(arr[i]), sum(arr[i])]中
    //进行二分搜索
    while(low<=high) {
        mid = (low+high)>>1;
        if(judge(mid)) {
            //res = max(res, mid);    //更新结果
            low = mid + 1;  //在右区间搜索
        }
        else {
            high = mid-1;   //在左区间搜索
        }
    }
    cout << low;

    _getch();
    return 0;
}