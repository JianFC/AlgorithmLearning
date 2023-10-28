#include <iostream>
#include <algorithm>

using namespace std;        //AcWing 1017. 怪盗基德的滑翔翼

const int N = 110;

int n;
int a[N], f[N];     //a原数组，f为DP数组

int main() {    
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

        int res = 0;
        //正向求解LIS
        for (int i = 1; i <= n; i ++) {  //以a[i]结尾的LIS解
            f[i] = 1;   //前一个数字为空
            for (int j = 1; j < i; j ++)
                if (a[i] > a[j])    //保证LIS性质
                    f[i] = max(f[i], f[j] + 1);     //DP方程
            res = max(res, f[i]);
        }

        //反向求解LIS，即为最长下降子序列
        for (int i = n; i >= 1; i --) {     
            f[i] = 1;
            for (int j = n; j > i; j --)    //反向
                if (a[i] > a[j])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }

        printf("%d\n", res);
    }

    return 0;
}