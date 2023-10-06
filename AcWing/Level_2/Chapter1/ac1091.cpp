#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //1091. 理想的正方形

const int N = 1010, INF = 0x3f3f3f3f;

int n, m, k;
int w[N][N];    //存储原矩阵
int row_max[N][N], row_min[N][N];   //存储每行的滑动窗口为k的最大值和最小值
int q[N];   //单调队列

void get_min(int a[], int b[], int tot) {   //a为原数组，b为结果数组，tot为a长度
    int hh = 0, tt = -1;    //初始时没有元素
    for (int i = 1; i <= tot; i ++) {
        if (hh <= tt && q[hh] <= i - k) hh ++;  //不算i，最多有k - 1个元素
        while (hh <= tt && a[q[tt]] >= a[i]) tt --;     //维护单调队列性质
        q[++ tt] = i;
        b[i] = a[q[hh]];    //更新b数组
    }
}

void get_max(int a[], int b[], int tot) {   //求最大值
    int hh = 0, tt = -1;
    for (int i = 1; i <= tot; i ++) {
        if (hh <= tt && q[hh] <= i - k) hh ++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt --;
        q[++ tt] = i;
        b[i] = a[q[hh]];
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf("%d", &w[i][j]);
            
    for (int i = 1; i <= n; i ++) { //预处理每一行的长度为k的区间最大值和最小值，存到窗口最右侧
        get_min(w[i], row_min[i], m);
        get_max(w[i], row_max[i], m);
    }
    
    int res = INF;
    int a[N], b[N], c[N];  //定义三个辅助数组，a把每一列拿出来，b存储列上最小值，c存储列上最大值
    for (int i = k; i <= m; i ++) {     //求列上的最小值和最大值，注意从k列开始
        for (int j = 1; j <= n; j ++) a[j] = row_min[j][i];       //拿row_min中每一列，注意是a[j]
        get_min(a, b, n);   //求k * k矩阵最小值
        
        for (int j = 1; j <= n; j ++) a[j] = row_max[j][i];     //拿row_max中每一列
        get_max(a, c, n);   //求最大值
        
        for (int j = k; j <= n; j ++) res = min(res, c[j] - b[j]);  //求出右下角坐标时(j, i)的矩阵min(max - min)
    }
    
    printf("%d\n", res);
    
    return 0;
}
