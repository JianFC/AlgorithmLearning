// P1308 [NOIP2011 普及组] 统计单词数

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <conio.h>
#include <cctype>
#include <string>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1e6+10;
char arti[maxn];    //保存文章
char word[15];  //待查找单词
int pos = 0x7fffffff, num=0;    //pos代表单词出现的位置，num代表出现的次数

//大写变小写
inline char translate(char x) {
    if (x>'z'|| x<'a') {
        x = x + 'a'-'A';
    }
    return x;
}

int main(void) {
    cin.getline(word, maxn);
    cin.getline(arti, maxn);

    fp(i, 0, int(strlen(word)-1)) word[i] = translate(word[i]);

    int len = strlen(arti);
    char temp[15]; int cntt=0;
    for (int i=0; i<len; i++) {
        
    }

    if (num!=0) cout << num << " " << pos;
    else cout << -1;
    
    _getch();
    return 0;
}

// 20210409
// --------------------------------------TLE----------------------------------------
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// #include <conio.h>
// #include <cctype>
// #include <string>
// #define fp(i, l, r) for(register int i=(l); i<=(r); i++)
// #define fd(i, l, r) for(register int i=(l); i>=(r); i--)
// typedef long long ll;

// using namespace std;
// const int maxn = 1e6+10;
// char arti[maxn];    //保存文章
// struct node {
//     char word[15];  //保存单词
//     int pos;    //首次出现位置
//     int num;    //出现次数
//     node(char *dword, int dpos, int dnum) {
//         strcpy(word, dword);
//         pos = dpos; num = dnum;
//     }
//     node() {}
// } words[100010];
// int cnt=0;    //words数组计数
// char word[15];  //待查找单词

// //大写变小写
// inline char translate(char x) {
//     if (x>'z'|| x<'a') {
//         x = x + 'a'-'A';
//     }
//     return x;
// }

// int main(void) {
//     cin.getline(word, maxn);
//     cin.getline(arti, maxn);

//     int len = strlen(arti);
//     char temp[15]; int cntt=0; int flag = 1;
//     for (int i=0; i<len; i++) {
//         if (arti[i]!=' ') {
//             temp[cntt++]=translate(arti[i]);    //temp暂时存储单词
//         } 

//         if(arti[i] == ' ' || i==len-1) {
//             if (cntt!=0) {
//                 temp[cntt]='\0'; flag = 1;  //flag判断该单词是否存在
//                 //cout << temp << endl;
//                 fp(j, 1, cnt) {
//                     //words数组中存在该单词
//                     if (strcmp(words[j].word, temp) == 0) {
//                         words[j].num++; flag = 0;
//                         break;
//                     }
//                 }
//                 //words数组中无该单词
//                 if (flag) words[++cnt] = node(temp, i-cntt, 1);
//                 //收尾工作
//                 cntt=0;
//             }
//         }
//     }

//     //大写转换为小写
//     for (int i=0; i<int(strlen(word)); i++) word[i]=translate(word[i]);

//     flag = 0;   //假设要查询的单词不存在
//     fp(i, 1, cnt) {
//         if (strcmp(words[i].word, word) == 0) {
//             cout << words[i].num << " " << words[i].pos; flag = 1;
//             break;
//         }
//     }
    
//     if (!flag) cout << -1;

//     _getch();
//     return 0;
// }
