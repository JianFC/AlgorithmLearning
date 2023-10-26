#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //AcWing 303. 运输小猫

typedef long long LL;

const int N = 100010, M = N, P = 110;

int n, m, p;
LL d[N], t[M], a[N], s[M];     // d[i]表示题中d[i]的前缀和，t[i]表示第i只猫结束玩的时间，a[i]表示t[i]-d[i]，s[i]表示a[i]的前缀和
LL f[P][M];    //f[j][i]表示前i只小猫，划分为j组的所有方案，如此定义优化缓存命中率
int q[M];       //存储凸包下边界的单调队列

LL get_y(int k, int j) {
    return f[j - 1][k] + s[k];      //用j - 1层的状态更新j层的状态，注意y的定义
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    
    for (int i = 2; i <= n; i ++) {
        scanf("%lld", &d[i]);
        d[i] += d[i - 1];       //转换为前缀和
    }
    
    for (int i = 1; i <= m; i ++) {
        int h;
        scanf("%d%lld", &h, &t[i]);
        a[i] = t[i] - d[h];     //更新a[i]
    }
    
    sort(a + 1, a + 1 + m);     //将a数组从小到大排序，方便分析
    
    for (int i = 1; i <= m; i ++) s[i] = s[i - 1] + a[i];   //求s[i]的前缀和
    
    //据定义初始化f数组，注意从0开始初始化
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i <= p; i ++) f[i][0] = 0;      
    
    for (int j = 1; j <= p; j ++) {
        int hh = 0, tt = 0;     //初始时单调队列中存在f[j][0]第二维的下标
        q[0] = 0;    //更新q[0]
        
        for (int i = 1; i <= m; i ++) {
            //查询前维护队列，保证队列中至少有两个元素，除法变乘法保证精度
            while (hh < tt && (get_y(q[hh + 1], j) - get_y(q[hh], j)) <= a[i] * (q[hh + 1] - q[hh])) hh ++;
            
            int k = q[hh];      //取出第一个满足要求的点
            f[j][i] = f[j - 1][k] - a[i] * k + s[k] + a[i] * i - s[i];      //DP方程
            
            //插入前维护队列，除法变乘法
            while (hh < tt && (get_y(q[tt], j) - get_y(q[tt - 1], j)) * (i - q[tt]) >= 
                (get_y(i, j) - get_y(q[tt], j)) * (q[tt] - q[tt - 1])) tt --;
            q[++ tt] = i;   //i点入队
        }
    }
    
    printf("%lld\n", f[p][m]);
    
    return 0;
}
