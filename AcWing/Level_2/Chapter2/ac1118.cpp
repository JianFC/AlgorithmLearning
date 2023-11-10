#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;        //1118. 分成互质组

const int N = 12;

int n;
int p[N];   //存储正整数组
int group[N][N];    //group[i]存储第i组的所有互质的数
bool st[N];     //每一层搜索时进行判重
int ans = N;    //存储全局最大值，最坏情况下为每一个数一组

int gcd(int a, int b) {     //a和b不互质当且仅当最大公约数大于1
    return b ? gcd(b, a % b) : a;   //gcd模板
}

bool check(int group[], int gc, int i) {    //判断元素数量为gc的group数组中，是否有元素和i不互质
    for (int j = 0; j < gc; j ++)
        if (gcd(p[group[j]], p[i]) > 1)
            return false;   //存在元素不互质
    return true;    //所有元素和i互质
    
}

void dfs(int g, int gc, int tc, int start) {    //组的数量，组内元素数量，总共划分了多少元素，可以用的最小下标
    if (g >= ans) return;   //剪枝，分组数量已经超过ans
    if (tc == n) {
        ans = g;   //更新ans
        return;     //搜索完毕
    }
    
    bool flag = true;   //记录该组是否还能放下新的元素
    for (int i = start; i < n; i ++)        //组合问题，人为确定顺序，从start开始
        if (!st[i] && check(group[g], gc, i)) {
            st[i] = true;   //第i个数已经使用
            
            group[g][gc] = i;   //更新group数组，group可以不用恢复现场
            dfs(g, gc + 1, tc + 1, i + 1);  //继续下一层递归       
            
            st[i] = false;  //恢复现场
            flag = false;   //key：当该组还能加入元素时，则不需要新开组
        }
    
    if (flag) dfs(g + 1, 0, tc, 0);     //该组不能再放下任何一个元素，需要新开一个组
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> p[i];   //读入数据
    
    dfs(1, 0, 0, 0);    //初始时一个组，组内元素数量，总共划分了0个元素，改组可以放的元素的最小下标是0
    
    cout << ans << endl;
    
    return 0;
}