#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;    //479. 加分二叉树

const int N = 35;

int n;
int w[N];       //每个节点的得分
int f[N][N], g[N][N];   //f[L][R]所有中序遍历是[L, R]的二叉树的得分最大值，
                        //g[L][R]记录f[L][R]由哪个状态转移而来，记录[L, R]根节点

void dfs(int l, int r) {    //输出方案
    if (l > r) return ;     //区间为空，返回
    
    int root = g[l][r];     //找到区间的根节点
    cout << root << " ";    //输出根节点
    
    dfs(l, root - 1);   //输出左子树
    dfs(root + 1, r);   //输出右子树
}
                        
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> w[i];
    
    for (int len = 1; len <= n; len ++)     //枚举区间长度
        for (int l = 1; l + len - 1 <= n; l ++) {   //枚举左端点
            int r = l + len - 1;
            if (len == 1) {
                f[l][r] = w[l];     //叶节点得分为自己
                g[l][r] = l;    //记录根节点
            }
            else {
                for (int k = l; k <= r; k ++) { //枚举根节点（分界线）
                    int left = k == l ? 1 : f[l][k - 1];      //左子树得分
                    int right = k == r ? 1 : f[k + 1][r];     //右子树得分
                    int score = left * right + w[k];    //当前分割情况下得分
                    if (f[l][r] < score) {  //输出字典序最小，从左往右便遍历，不能取等
                        f[l][r] = score;    //更新状态表示数组
                        g[l][r] = k;    //记录[l, r]的根节点
                    }
                }
            }
        }
    
    cout << f[1][n] << endl;    //输出结果
    dfs(1, n);  //输出方案
    
    return 0;
}