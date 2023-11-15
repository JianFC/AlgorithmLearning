#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;            //171. 送礼物

typedef long long LL;

const int N = 50;

int n, m, k;   //m表示重量上限, k表示对前n件物品进行打表
int w[N];   //w[i]表示每件物品的重量
int weight[1 << 24], cnt = 1;    //将前25件物品的重量组合打表，初始时将0加入weight，cnt从1开始，需要128M空间
int ans;    //存储全局最大值

void dfs1(int u, int s) {
    if (u == k) {   //第一部分搜索完毕
        weight[cnt ++] = s;     //加入数组
        return ;
    }
    
    //不放第u个物品
    dfs1(u + 1, s);
    //放第u个物品，注意可行性剪枝
    if ((LL)s + w[u] <= m) dfs1(u + 1, s + w[u]);       //转为LL，防止溢出
}

void dfs2(int u, int s) {
    if (u == n) {   //所有物品搜索完毕
        int l = 0, r = cnt - 1;     //二分表中小于等于m - s的最大值（左区间答案）
        while (l < r) {     //二分
            int mid = l + r + 1 >> 1;       //左区间二分+ 1防止死循环
            if (weight[mid] <= m - s) l = mid;
            else r = mid - 1;
        }
        
        ans = max(ans, weight[l] + s);  //更新答案，0在队列中，不会超出m的范围
        return ;
    }
    
    //不放第u个物品
    dfs2(u + 1, s);
    //放第u个物品
    if ((LL)s + w[u] <= m) dfs2(u + 1, s + w[u]);
}

int main() {
    cin >> m >> n;      //注意输入顺序
    for (int i = 0; i < n; i ++) cin >> w[i];   //读入重量
    
    //优化搜索顺序
    sort(w, w + n);
    reverse(w, w + n);      //从大到小排序
    
    k = n / 2 ;  //第一部分的计算量，不额外增加，防止超出n的范围
    dfs1(0, 0);      //搜索第一部分，从第0个物品开始，当前总重量为0
    
    //对weight排序并去重，便于后续二分，注意weight数组的有效长度为cnt
    sort(weight, weight + cnt);
    cnt = unique(weight, weight + cnt) - weight;  //更新去重后的weight数量，unique返回非重复元素的下一个位置
    
    //对第二部分进行搜索
    dfs2(k, 0);     //从第k个物品开始搜索第二部分，当前第二部分总重量为0
    
    cout << ans << endl;        //输出答案
    
    return 0;
}