#include <iostream>

using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N];   //f[i]表示以a[i]结尾的上升子序列的最大长度
int g[N];   //存储转移的过程

int main(void) {    //最长上升子序列打印路径
    scanf("%d", &n);

    for (int i=1; i<=n; i++) scanf("%d", &a[i]);

    for (int i=1; i<=n; i++) {
        f[i] = 1;   //当只有一个数的情况，最少为1
        g[i] = 0;   //当只有一个数的情况，没有前驱
        //枚举倒数第二个数
        for (int j=1; j<i; j++)
            if (a[j] < a[i]) 
                if (f[i] < f[j]+1) {
                    f[i] = f[j] + 1;
                    g[i] = j;   //存储转移的前驱是谁，结束之后通过往前递推得出转移路径
                }
    }

    int k = 1;  //记录最优解下标
    //搜索f[i]最大值
    for (int i=1; i<=n; i++) 
        if (f[k] < f[i]) k = i;

    cout << f[k] << endl;

    //倒着输出最长子序列
    for (int i=0, len=f[k]; i<len; i++) {
        printf("%d ", a[k]);
        k = g[k];
    }

    return 0;
}