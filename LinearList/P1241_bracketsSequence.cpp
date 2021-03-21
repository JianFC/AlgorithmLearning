#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1100;
int bkt[300];   //数字化括号
stack<int> seq; //存储左括号([下标的栈
char s[maxn];   //存储输入的括号序列
int sflag[maxn] = {0};    //标记括号序列的匹配情况
int l, k;
char ch;
char bkt_out[9] = {'}', '>', ']', ')', '0', '(', '[', '<', '{'};   //输出时补全未匹配的括号

int main(void) {
    // 学习该数字化字符的方式
    bkt['('] = -1; bkt[')'] = 1;
    bkt['['] = -2; bkt[']'] = 2;
    bkt['<'] = -3; bkt['>'] = 3;
    bkt['{'] = -4; bkt['}'] = 4;
    cin >> s;
    l = strlen(s);
    for (int i=0; i<l; i++) {
        ch = s[i];
        if (bkt[int(ch)] < 0) {
            seq.push(i);    //将各左括号的下标压入栈中
        }
        else {
            if (!seq.empty()) {     //注意对栈的判空！！！！
                k = seq.top();  //取栈首元素
                if (bkt[int(s[k])] + bkt[int(ch)] == 0) {
                    sflag[i] = 1; sflag[k] = 1;
                    seq.pop();  //左括号出栈
                }
            }
        }
    }

    //输出
    for (int i=0; i<l; i++) {
        if (sflag[i] == 1) cout << s[i];
        else {
            if (bkt[int(s[i])] < 0) cout << s[i] << bkt_out[bkt[int(s[i])]+4];
            else cout << bkt_out[bkt[int(s[i])]+4] << s[i];
        }
    }

    _getch();
    return 0;
}

