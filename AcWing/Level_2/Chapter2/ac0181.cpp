#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;        //181. 回转游戏

const int N = 24;

/* q的编号对应的数转换为图形如下
            0       1
            2       3
    4   5   6   7   8   9   10
            11      12
    13  14  15  16  17  18  19
            20      21
            22      23
*/


int op[8][7] = {    //A-H操作每个操作所对应的操作数的下标
    {0, 2, 6, 11, 15, 20, 22},      //A
    {1, 3, 8, 12, 17, 21, 23},      //B
    {10, 9, 8, 7, 6, 5, 4},         //...
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},   
    {4, 5, 6, 7, 8, 9, 10},         //H
};

int opposite[8] = {5, 4, 7, 6, 1, 0, 3, 2};     //opposite[i]表示操作i的逆操作的序号
int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};  //中间8个数所对应的下标

int q[N];   //存储#字形图形
int path[100];      //存储搜索路径

int f() {   //估价函数：8 - 出现次数最多的数的出现次数
    static int cnt[4] = {0};     //[1][2][3]分别记录1，2，3出现的次数，定义为static，避免重新分配
    memset(cnt, 0, sizeof cnt);     //每次重新设置cnt
    
    for (int i = 0; i < 8; i ++) cnt[q[center[i]]] ++;  //更新cnt
    
    int s = 0;  //出现次数最多的数的出现次数
    for (int i = 1; i <= 3; i ++) s = max(s, cnt[i]);   //更新s
    return 8 - s;   //估价函数值
}

void operate(int x) {   //对q进行x操作
    int t = q[op[x][0]];    //记录下x操作的第0个数的值
    for (int i = 0; i < 6; i ++) q[op[x][i]] = q[op[x][i + 1]];     //循环移动后面的数
    q[op[x][6]] = t;    //更新最后一个数
}

bool dfs(int depth, int max_depth, int last) {  //当前迭代深度，最大迭代深度，上一个操作序号
    if (depth + f() > max_depth) return false;  //超出最大深度
    if (f() == 0) return true;      //找到一种合法方案
    
    for (int i = 0; i < 8; i ++)
        if (opposite[i] != last) {  //剪枝操作，只有当不为逆操作时才搜索，trick，取opposite[i]不会数组越界
            operate(i);     //进行i操作
            path[depth] = i;    //记录操作
            if (dfs(depth + 1, max_depth, i)) return true;      //找到合法解
            operate(opposite[i]);   //恢复现场
        }
    
    return false;   //没有搜到答案
}

int main() {
    while (cin >> q[0], q[0]) {     //多组测试用例
        for (int i = 1; i < N; i ++) cin >> q[i];   //读入数据
        
        int depth = 0;
        while (!dfs(0, depth, -1)) depth ++;    //迭代加深，参数分别是：当前搜到第0层，最大层数，上一个操作序号
        
        if (!depth) printf("No moves needed");
        else {
            for (int i = 0; i < depth; i ++) printf("%c", path[i] + 'A');    
        }
        printf("\n%d\n", q[6]);     //输出中间8个数任意一个数即可
    }
    
    return 0;
}


