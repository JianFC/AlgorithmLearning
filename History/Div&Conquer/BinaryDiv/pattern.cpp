//二分查询，二分法求最大值最小or最小值最大
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

//---------------------------------二分查询__开始--------------------------------------------
//非递归算法
//假设arr从小到大有序
inline int binarySearch(int* arr, int key, int n) {    //arr[1-n]是有序数组，key是待查找的关键字，n是数组长度
    int low = arr[1];   //假设arr从1开始
    int high = arr[n];

    while(low<=high) {
        int mid = (low+high)>>1;    //(low+high)/2并向下取整
        if (key == arr[mid]) return mid;
        else if (key < arr[mid]) high = mid-1;
        else low = mid + 1;
    }

    return -1;  //key在数组中未找到，两种情况: key小于arr中最小值，key大于arr中最大值

}

//递归算法
inline int binarySearch(int *arr, int low, int high, int key) {
    int mid = (low+high)>>1;
    while(low <= high) {
        if (key == arr[mid]) return mid;
        else if (key < arr[mid]) { high = mid-1; return binarySearch(arr, low, high, key); }
        else { low = mid+1; return binarySearch(arr, low, high, key); }
    }

    return -1;  //未找到
}

//---------------------------------二分查询__结束--------------------------------------------

//-----------------------------二分最大最小or最小最大__开始-----------------------------------

//见洛谷例题：P1182 P2678 P1824 P1843

//-----------------------------二分最大最小or最小最大__开始-----------------------------------

int main(void){

    _getch();
    return 0;
}