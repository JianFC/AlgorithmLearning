#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;            //166. 数独

const int N = 9, M = 1 << N;    //M表示状态的上限

int ones[M], map[M];    //ones[i]表示状态i中有多少个1(可以使用的数)，map[i]表示lowbit运算结果为i的指数是多少
int row[N], col[N], cell[3][3];     //row[i], col[i], cell[i][j]分别表示第i行，第i列，第(i, j)位置的九宫格的状态
char str[100];      //用字符串存储数独

void init() {
    for (int i = 0; i < N; i ++) row[i] = col[i] = (1 << N) - 1;    //初始时每行每列状态都为511
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j ++)
            cell[i][j] = (1 << N) - 1;      //数独每个九宫格状态也为511
}

void draw(int x, int y, int t, bool is_set) {   //依据is_set将(x, y)位置上置为t(is_set == true),或者置为.(is_set == false)
    if (is_set) str[x * N + y] = '1' + t;   //t的范围是[0, 8]
    else str[x * N + y] = '.';  //便于DFS时恢复现场
    
    //恢复对应的row，col和cell
    int v = 1 << t;     //标记第t个数的状态
    if (!is_set) v = -v;    //还原第t个数的状态
    
    row[x] -= v;    //更新row的状态，注意是-
    col[y] -= v;    //更新col的状态
    cell[x / 3][y / 3] -= v;    //更新(x, y)所在九宫格的状态
}

int lowbit(int x) {
    return x & -x;  //lowbit操作
}

int get(int x, int y) {     //返回数独中(x, y)所在位置上能填的数的十进制状态表示
    return row[x] & col[y] & cell[x / 3][y / 3];    //二进制状态中所有为1的位置对应的下标可以转换为能填的数字
}

bool dfs(int cnt) {     //cnt表示当前数独还需要填的位置数量，返回值bool表示能否填写成功
    if (!cnt) return true;  //当cnt == 0时，数独填写完毕
    
    //优化搜索顺序，找到分支数量最少的可以填写的节点
    int minv = 10;      //记录分支数量
    int x, y;   //记录分支数量最少节点的位置
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
            if (str[i * N + j] == '.') {    //首先保证该位置可以进行填写
                int state = get(i, j);  //得到可以填写的数的二进制状态的十进制表示
                
                if (ones[state] < minv) {       //找到一个合法位置
                    minv = ones[state];     //更新操作
                    x = i, y = j;   
                }
            }
    
    int state = get(x, y);      //返回条件保证x，y一定会被赋值,state表示可以填的数的二进制状态的十进制
    for (int i = state; i; i -= lowbit(i)) {    //枚举state中记录的可以填的数，并进一步搜索，i > 0隐含可行性剪枝
        int t = map[lowbit(i)];     //求出state中最后一个1的位置，并转换为对应的[0, 8]范围的指数t
        draw(x, y, t, true);    //将该位置进行填充
        if (dfs(cnt - 1)) return true;      //填充成功，注意不能写cnt --
        
        draw(x, y, t, false);   //填充失败，恢复现场
    }
    
    return false;   //该分支填充失败
}

int main() {
    //对ones和map数组进行打表
    for (int i = 0; i < N; i ++) map[1 << i] = i;   //快速将lowbit结果转换为可以填的数字(0, 8)，后续处理时 + “1”
    for (int i = 0; i < 1 << N; i ++)
        for (int j = 0; j < N; j ++)
            ones[i] += i >> j & 1;      //求出状态i转换为二进制后中的1的个数
            
    while (cin >> str, str[0] != 'e') {     //读入数据trick
        init();     //初始化row，col和cell
        
        int cnt = 0;    //记录该数独中可以填的位置的数量
        for (int i = 0, k = 0; i < N; i ++)     //k表示二维数独中(i, j)位置在str中的下标
            for (int j = 0; j < N; j ++, k ++) 
                if (str[k] != '.') {
                    int t = str[k] - '1';   //将数字转为为[0, 8]，便于操作
                    draw(i, j, t, true);    //更新row，col和cell的初始状态
                }
                else cnt ++;    //更新cnt
        
        dfs(cnt);   //dfs传入参数为可以填的位置数量，当cnt == 0时，数独填写完毕
        
        puts(str);  //输出结果
    }
    
    return 0;
}
