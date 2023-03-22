#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 12, M = 1<<N;

int n, m;
LL f[N][M];    //f[i][j]表示摆放第i列，上一列延伸到第i列的行的状态是j的方案数量
bool st[M];     //预处理每个行状态是否具有连续偶数个0

int main(void) {        //AcWing 291. 蒙德里安的梦想
    while (scanf("%d%d", &n, &m), n || m) {

        memset(f, 0, sizeof f);     //对每组数据清空f

        //预处理每个行状态是否具有连续偶数个0
        for (int i=0; i<1<<n; i++) {
            st[i] = true;   //初始化为true
            int cnt = 0;    //存储连续偶数个0的个数
            for (int j=0; j<n; j++)     //对每一个状态枚举每一行
                if (i >> j & 1) {       //当前行是1
                    if (cnt & 1) st[i] = false;     //奇数个1
                    cnt = 0;    //cnt清零
                }
                else cnt++;

            if (cnt & 1) st[i] = false;
        }

        //DP过程
        f[0][0] = 1;    //摆放第0列，没有上一列，所以行状态是0的方案数为1
        //其余f[0][0~1<<n] = 0

        for (int i=1; i<=m; i++)
            for (int j=0; j<1<<n; j++)
                for (int k=0; k<1<<n; k++)
                    if ((j&k) == 0 && st[j | k]) 
                        f[i][j] += f[i-1][k];

        cout << f[m][0] << endl;    //f[m][0]中存储的才是答案   
    }

    return 0;
}
