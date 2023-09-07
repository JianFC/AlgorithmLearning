#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
char p[N], s[M];
int ne[N];

int main(void) {    //AcWing 831. KMP字符串
    scanf("%d%s%d%s", &n, p + 1, &m, s + 1);


    //求出模板串p的next数组，定义ne[1]=0, 即如果第二个字符没有匹配
    //,则只能从头开始匹配。所以i从2开始，j=0表示从头匹配
    for (int i = 2, j = 0; i <= n; i++) {
        //结束条件：j=0 或者 已经匹配
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;	//i与j+1匹配
        ne[i] = j; 	//更新ne数组
    }


    //求与s串的匹配位置
    //假设待匹配串s的[1, i-1]与模板串p[1, j]已经匹配，
    //当前比较的位置是s[i]与p[j+1]
    for (int i = 1, j = 0; i<=m; i++) {
        //j没有退回起点 并且 当前位置不匹配
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n) {	//匹配成功
            printf("%d ", i - n);
            j = ne[j];	//匹配成功之后，后退一步， 
        }
    }

    return 0;
}
