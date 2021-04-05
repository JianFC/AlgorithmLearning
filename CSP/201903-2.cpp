#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
char ex[20];
char ch;
stack<char> op; //操作符栈
stack<int> num; //操作数栈
int n;

int main(void) {
    cin >> n;
    int temp, a, b;  
    fp(i, 1, n) {
        while(!op.empty()) op.pop();    //清栈
        while(!num.empty()) num.pop(); 
        scanf("%s", ex);
        for (int i=0; i<int(strlen(ex)); i++) {
            ch = ex[i];
            if (ch>='0' && ch<='9') { num.push(ch-'0'); }
            //注意对减号的处理，防止出栈时由于运算顺序不对导致结果出错！,另外注意需要将字符数字减'0'转换为int数字！
            else if (ch == '-') { temp = (ex[i+1]-'0')*(-1); num.push(temp); op.push('+'); i++; }  
            else if (ch == '+') { op.push(ch);}
            else if (ch == 'x' || ch == '/') {
                a = num.top(); num.pop();
                b = ex[i+1] - '0';
                if (ch == 'x') temp = a*b;
                else temp = a/b;
                num.push(temp);
                i++;    //跳过下一个字符，下一个字符已经被提前处理
            }
        }

        while(!op.empty()) {
            a = num.top(); num.pop();
            b = num.top(); num.pop();
            num.push(a+b);
            op.pop(); 
        }

        printf("%s\n", num.top()==24? "Yes":"No");
    }

    _getch();
    return 0;
}