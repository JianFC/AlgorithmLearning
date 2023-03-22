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
const int maxn = 1e5+10;
int arr[maxn] = {0};
int n, c;
int low, high, mid;  //二分法的上界与下界
int res = 0;

//模板函数，通过x的取值来判定在右区间搜索还是左区间搜索
inline bool judge(int x) {
    int tot = 1;    //能够安排的奶牛个数，初始化为1
    int precow = 1;  //上一只奶牛的位置，第一只奶牛一定安排在数组的第一个位置(反证法证明)
    //对数组剩余的元素进行遍历，找出所有在间距为x的情况下能安放奶牛的点
    fp(i, 2, n) {
        if (arr[i]-arr[precow] >= x) { tot++; precow=i; }   //更新tot与precow
        // or 
        // if (arr[i]-arr[precow] > x) { tot++; precow=i; }

        if (tot>=c) return true;    //当能够安放的奶牛数量大于等于题目要求数量时，返回true，在右区间继续搜索
    }
    return tot>=c;
}

int main(void) {
    cin >> n >> c;
    fp(i, 1, n) cin >> arr[i];
    sort(arr+1, arr+1+n);   //将隔间从小到大排序，以便进行二分搜索
    low = arr[1]; high = arr[n]-arr[1];     //初始化二分搜索边界，所求的最大的最小间隔一定在区间[arr[1], arr[n]-arr[1]]之内
    //对[low, high]区间进行二分搜索，时间复杂度O(logn)
    while(low <= high) {
        mid = (low+high)>>1;    //mid = (low+high)/2
        if (judge(mid)) {
            res = max(res, mid);    //mid为一个可能解，更新res，继续向右搜索
            low = mid + 1;  //[mid+1, high]右区间搜索
        }
        else {
            high = mid - 1; //向左搜索
        }
    } 
    cout << res;
    // 与judge函数中修改对应
    // cout << low

    _getch();
    return 0;
}