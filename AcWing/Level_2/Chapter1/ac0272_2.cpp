#include <iostream>
#include <algorithm>

using namespace std;    //272. 最长公共上升子序列，优化做法，时间复杂度O(n^2)

const int N = 3030;

int n;
int a[N], b[N];     //a和b数组分别代表两个序列
int f[N][N];    //f[i][j]代表的集合：所有由a序列前i个字符，b序列前j个字符，且以b[j]
                //结尾的公共上升子序列长度的集合; 集合属性为求长度最大值

int main(void) {    
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    
    for (int i = 1; i <= n; i ++) {
        
        int maxv = 1;   //maxv表示[1, j - 1]中f[i - 1][k]的最大值
        for (int j = 1; j <= n; j ++) {
            f[i][j] = f[i - 1][j];
            
            if (b[j] < a[i]) maxv = max(maxv, f[i - 1][j] + 1);     //求出f[i - 1][k] + 1的最大值
            if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);     //a[i] == b[j]时更新f[i][j];
            
            // if (a[i] == b[j]) {
            //     f[i][j] = max(f[i][j], 1);
            //     for (int k = 1; k < j; k ++)    //找到从[1, j - 1]中b[k]小于a[i]的f[i - 1][k]最大值，可以往上提
            //         if (b[k] < a[i]) //将b[j]换为a[i]后可以发现该循环可以和上层循环
            //                          //一起完成，故提出maxv变量，减少一层循环
            //              f[i][j] = max(f[i][j], f[i - 1][k] + 1);
            // }
        }
        
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++) res = max(res, f[n][i]);
    
    printf("%d", res);
    
    return 0;
}