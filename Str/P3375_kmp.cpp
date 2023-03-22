// kmp算法 
// references: https://www.zhihu.com/question/21923021
// TODO:算法复杂度分析(摊还分析？？)
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <conio.h>
typedef long long ll;
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)

using namespace std;
const int maxs = 1e6+10;
char s1[maxs], s2[maxs];
int nxt[maxs] = {0};

//计算Next数组
void buildNxt() {
    unsigned int i =1;
    nxt[0] = 0; int now = 0;

    while(i<strlen(s2)) {
        if (s2[i] == s2[now]) nxt[i++] = ++now;     //当S2[now] == S2[i]的情况，计算nxt[i]
        else if(now) now = nxt[now-1];      //now！=0
        else i++;           //now=0;nxt[i] = now = 0;i++
    }
}
//利用next数组进行kmp模式匹配
void search() {
    unsigned int tar = 0, pos = 0;      //tar表示目标串当前下标位置，pos表示模式串下标位置，注意局部变量的初始化
    while (tar<strlen(s1)) {
        if (s2[pos] == s1[tar]) {
            tar++; pos++;
        }
        else if (pos) pos = nxt[pos-1]; //出现失配现象，模式串移至nxt[pos-1]位置
        else tar++;     //pos=0,从模式串开始处开始匹配

        //判断是否匹配模式串，注意书写位置
        if (pos == strlen(s2)) {
            cout << tar-pos+1 << endl;
            pos = nxt[pos-1];       //模式匹配成功，pos中存入下一个字符必不匹配，提前利用nxt数组更新pos位置
        }
    }
}

int main(void) {
    cin >> s1 >> s2;
    buildNxt();
    search();
    for (unsigned int i=0; i<strlen(s2); i++) cout << nxt[i] << " ";

    _getch();
    return 0;
}

// #include <iostream>

// using namespace std;

// const int maxm = 1e6+10, maxn = 1e5+10;

// int n, m;
// char p[maxn], s[maxm];
// int ne[maxn];

// int main(void) {
//     cin >> n >> p+1 >> m >> s+1;
//     for (int i=2, j=0; i<=n; i++) {
//         while (j && p[i] != p[j+1]) j = ne[j];
//         if (p[i] == p[j+1]) j++;
//         ne[i] = j;
//     }
    
    
//     for (int i=1, j=0; i<=m; i++) {
//         while (j && s[i] != p[j+1]) j = ne[j];
//         if (s[i] == p[j+1]) j++;
//         if (j==n) {
//             cout << i-j << " ";
//             j = ne[j];
//         }
//     }
    
//     return 0;
// }