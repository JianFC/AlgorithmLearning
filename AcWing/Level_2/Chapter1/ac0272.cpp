#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3030;

int n;
int a[N], b[N];     //a和b数组分别代表两个序列
int f[N][N];    //f[i][j]代表的集合：所有由a序列前i个字符，b序列前j个字符，且以b[j]
                //结尾的公共上升子序列长度的集合; 集合属性为求长度最大值

int main(void) {    //272. 最长公共上升子序列，暴力做法，可进一步优化
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    for (int i=1; i<=n; i++) scanf("%d", &b[i]);
    
    //三重循环暴力做法，可进一步对代码优化降维
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) {
            f[i][j] = f[i-1][j];    //不包含a[i]的情况
            
            if (a[i] == b[j]) {     //包含a[i]的情况，此时必有a[i] == b[j];
                f[i][j] = max(f[i][j], 1);  //LIS问题，倒数第二个字符为空，只有b[j]
                for (int k=1; k<j; k++) {
                    //满足条件时，求LIS问题的解，注意是f[i-1][k]+1
                    if (b[k] < b[j]) f[i][j] = max(f[i][j], f[i-1][k]+1);
                }
            }
        }
    
    //扫描以哪个b[j]结尾的公共上升子序列长度最大
    int res = 0;
    for (int i=1; i<=n; i++) res = max(res, f[n][i]);
    
    printf("%d", res);
    
    return 0;
}