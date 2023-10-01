#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

// trick：简化pair元素书写
#define x first
#define y second

using namespace std;    //524. 愤怒的小鸟

typedef pair<double, double> PDD;

const int N = 20, M = 1 << 18;
const double eps = 1e-8;    //浮点数比较时的精度

int n, m;
PDD q[N];   //存储N个点
int path[N][N];     //path[i][j]表示由i, j两点确定的抛物线能经过的点的状态（二进制表示）
int f[M];   //f[s]表示所有状态s的方案的抛物线数量的最小值

int cmp(double x, double y) {  //浮点数比较trick，注意返回值类型
    if (fabs(x - y) < eps) return 0;    //x == y
    if (x < y) return -1;
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T --) {
        cin >> n >> m;  //m的作用时OI比赛时根据数据范围骗分
        
        for (int i = 0; i < n; i ++) cin >> q[i].x >> q[i].y;   //存储点的信息
        
        memset(path, 0, sizeof path);   //多组数据
        //处理path数组
        for (int i = 0; i < n; i ++) {  //从前往后枚举确定抛物线的第一个点
            path[i][i] = 1 << i;    // path[i][i] = 1 << i;    //规定经过i, i的点状态，便于状态转移方程计算，有的数据只能单独用一条线经过。
            
            for (int j = 0; j < n; j ++) {  //枚举第二个点
                double x1 = q[i].x, y1 = q[i].y;    //第一个点
                double x2 = q[j].x, y2 = q[j].y;    //第二个点
                
                if (!cmp(x1, x2)) continue;     //两个点横坐标相同，不能确定抛物线
                //计算有i，j两点确定的抛物线的a和b
                double a = (y1 / x1 - y2 / x2) / (x1 - x2);   //根据公式计算
                double b = y1 / x1 - a * x1;
                
                if (cmp(a, 0) >= 0) continue;   //a必须严格小于0
                
                //计算i，j确定的抛物线能经过的点，更新path
                int state = 0;
                for (int k = 0; k < n; k ++) {  //枚举每个点
                    double x = q[k].x, y = q[k].y;
                    if (!cmp(a * x * x + b * x, y)) state += 1 << k;    //第k个点能到
                }
                
                path[i][j] = state; //更新path[i][j]
            }
        }
        
        //状态压缩DP过程
        memset(f, 0x3f, sizeof f);  //初始化f
        f[0] = 0;   //初始化
        //从前往后递推, 枚举到1 << n - 1的位置，最后全是1的状态所有点都已经过，用它不能更新任何状态
        for (int i = 0; i + 1 < 1 << n; i ++) {
            int x = 0;  //找到一个状态i不能到的点
            
            for (int j = 0; j < n; j ++)
                if (!(i >> j & 1)) {
                    x = j;  //找到该点
                    break;
                }
            
            //枚举可以消灭x的抛物线，并更新状态
            for (int j = 0; j < n; j ++)
                f[i | path[x][j]] = min(f[i | path[x][j]], f[i] + 1);   //状态转移方程
        }
        
        cout << f[(1 << n) - 1] << endl;  //输出所有点都走过的状态的f值即为答案，注意优先级
    }
    
    return 0;
}
