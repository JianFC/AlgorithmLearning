#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;    //1049. 大盗阿福

const int N = 100010, INF = 0x3f3f3f3f;

int n;
int w[N], f[N][2];  //w[i]存储第i家店的现金数量，f[i][0]表示第i家店不选的状态，1代表选的状态

int main() {
    int T;
    scanf("%d", &T);
    
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);   //从一号点开始输入
        
        f[0][0] = 0, f[0][1] = -INF;    //初始化,设置虚拟入口节点，入口只能走到0的状态，不能走到1
        for (int i = 1; i <= n; i ++) {     //从前往后考虑每个店铺
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);    //第一个状态计算方式
            f[i][1] = f[i - 1][0] + w[i];           //第二个状态计算方式
        }
        
        printf("%d\n", max(f[n][0], f[n][1]));      //在两个状态中选择最大值
    }
    
    
    return 0;
}