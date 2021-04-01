#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <conio.h> 
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
const int maxn = 1e3+5;
int a[maxn];    //待排序数组

//------------------------------冒泡排序__开始----------------------------
inline void bubble_sort(int n) {
    int flag = 1;
    int temp;
    for (int i=n; i>1 && flag; i++) {
        flag = 0;
        for (int j=1; j<n; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;
                flag = 1;
            }
        }
    }
}
//------------------------------冒泡排序__结束----------------------------


//-------------------------------------------快速排序__开始-----------------------------------
inline void swap(int& a, int& b) {
    int temp;
    temp = a; a = b; b = temp;
}

//分割函数，未优化
inline int partition(int* a, int low, int high) {
    int pivotkey = a[low];  //用子表的第一个记录作为枢轴记录
    while(low < high) {
        while(low<high && a[high]>=pivotkey) high--;
        swap(a[high], a[low]);
        while(low<high && a[low]<=pivotkey) low++;
        swap(a[low], a[high]);
    }
    return low; //or return high, 枢轴的位置在分割过程中不断地在high和low之间交换，
                //当分割结束时，high=low所在的位置便是枢轴的位置。
                //分割函数返回枢轴的位置，便于以其为分割点，分别对左右两边子数组进行递归排序。
}
//分割函数，优化版本
inline int partition_2(int *a, int low, int high) {
    int pivotkey = a[low];  //用子表的第一个记录作为枢轴记录
    //优化方案，只关心枢轴的最终位置，不关心其移动过程
    while (low < high) {
        while(low<high && a[high]>=pivotkey) high--;
        a[low] = a[high];
        while(low<high && a[low]<=pivotkey) low++;
        a[high] = a[low];
    }
    a[low] = pivotkey;
    return low;
}

//递归排序函数
inline void QSort(int* a, int low, int high) {
    if (low < high) {   //长度大于1
        int pivotloc = partition_2(a, low, high);   //将子表一分为2
        QSort(a, low, pivotloc-1);  //对左子表进行递归排序
        QSort(a, pivotloc+1, high); //对右子表进行递归排序
    }
}

//快速排序函数整合
inline void QuickSort(int* a) {
    QSort(a, 1, maxn);
}
//-------------------------------------------快速排序__结束-----------------------------------

int main(void) {
    //产生[x, y)之间的随机数
    int x = 1, y = 10001;
    srand((unsigned)time(NULL));
    for (int i=1; i<=maxn; i++) a[i] = x+rand()%(y-x);
    // bubble_sort(maxn);
    QuickSort(a);
    fp(i, 1, maxn) cout << a[i] << " ";

    _getch();
    return 0;
}