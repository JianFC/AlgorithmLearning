#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;            //167. 木棒

const int N = 70;

int n;
int w[N], sum, length;  //w[i]表示每个木棍的长度，sum表示木棍的长度总和，length表示枚举的木棒长度
bool st[N];     //st[i]表示第i根木棍是否被使用

bool dfs(int u, int s, int start) { //u表示当前枚举到哪根木棒，s表示当前木棒的长度，start表示当前木棒
                                    //从哪跟木棍开始用
    if (u * length == sum) return true;     //找到了一个合法方案
    if (s == length) return dfs(u + 1, 0, 0); //新开一根木棒，木棒长度为0，新开木棒从第0根木棍开始使用，注意return
    
    //剪枝3-1，按照组合问题枚举
    for (int i = start; i < n; i ++) {      //枚举使用哪根木棍，从start开始
        if (st[i]) continue;    //当前木棍已被之前的某根木棒使用
        if (s + w[i] > length) continue;    //可行性剪枝2：当前木棒不能拼接
        
        //使用第i根木棍
        st[i] = true;   //更新st
        if (dfs(u, s + w[i], i + 1)) return true;   //按照组合顺序枚举，找到一组合法方案，返回true
        
        st[i] = false;      //未找到答案，恢复现场
        
        //剪枝3-2
        int j = i;
        while (j < n && w[j] == w[i]) j ++; //已经排序，跳过所有长度和i相等的木棍
        i = j - 1;  //更新i
        
        //剪枝3-3
        if (!s) return false;   //木棒开头放置木棍后，续木棒失败，直接返回false
        
        //剪枝3-4
        if (s + w[i] == length) return false;   //木棒结尾放置后，后续木棒失败，直接返回false
    }
    
    return false;   //没有找到合法方案，返回false
}

int main() {
    while (cin >> n, n) {
        memset(st, 0, sizeof st);   //清空st
        sum = 0;    //清空sum
        for (int i = 0; i < n; i ++) {
            cin >> w[i];
            sum += w[i];    //更新sum
        }
        
        //剪枝2，优化搜索顺序，将木棍长度从大到小排序
        sort(w, w + n);
        reverse(w, w + n);  //注意进行反转操作
        
        length = 1;     //对木棒长度从小到大进行枚举
        while (true) {
            if (sum % length == 0 && dfs(0, 0, 0)) {  //可行性剪枝1，lenght|sum, dfs表示当前枚举第0根木棒，
                                                //当前木棒长度长度为0，（start）表示当前木棒从第0根木棍开始用
                cout << length << endl;
                break;      //找到最小长度，break掉
            }
            length ++;  //更新木棒长度
        }
    }
    
    return 0;
}