#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //180. 排书

const int N = 15;

int n;
int q[N];   //存储原排列
int w[5][N];    //迭代加深每一层中恢复现场使用

int f() {   //估价函数
    int tot = 0;    //当前q中不正确的后继关系数量
    for (int i = 0; i + 1 < n; i ++)
        if (q[i + 1] != q[i] + 1)   //没有按照1 ~ n的顺序排列，后继关系不正确
            tot ++;     //更新tot数量
    return (tot + 2) / 3;   //返回tot / 3的上取整值作为估价函数值
}

bool dfs(int depth, int max_depth) {
    if (depth + f() > max_depth) return false;  //当前层数 + 估价函数超出max_depth层
    if (f() == 0) return true;  //估价函数值为0，在max_depth范围内找到了解 
    
    for (int len = 1; len <= n; len ++)     //枚举区间长度
        for (int l = 0; l + len - 1 < n; l ++) {      //枚举区间左端点
            int r = l + len - 1;    //区间右端点
            //将a换到b后和将b换到a前等价，因此规定区间只能放到自己之后，不能放到自己位置之前
            for (int k = r + 1; k < n; k ++) {      //区间[l, r]可以放到点k右侧，即将[l, r]和[r + 1, k]交换
                memcpy(w[depth], q, sizeof q);      //对q进行备份
                
                int x, y = l;   //通过x和y的移动来完成区间交换
                for (x = r + 1; x <= k; x ++, y ++) q[y] = w[depth][x];     //写入[r + 1, k]部分
                for (x = l; x <= r; x ++, y ++) q[y] = w[depth][x];     //写入[l, r]部分
                if (dfs(depth + 1, max_depth)) return true;     //找到答案
                
                memcpy(q, w[depth], sizeof q);      //没有找到答案，恢复现场
            }
        }
    
    return false;   //没有找到答案，返回false
}

int main() {
    int T;
    cin >> T;
    while (T --) {
        cin >> n;
        for (int i = 0; i < n; i ++) cin >> q[i];
        
        int depth = 0;  //每次迭代加深的最大层数
        while (depth < 5 && !dfs(0, depth)) depth ++;   //最大层数小于5，每次从第0层开始迭代
        
        if (depth >= 5) puts("5 or more");      //在4层之内找不到解
        else cout << depth << endl;
    }
    
    return 0;
}