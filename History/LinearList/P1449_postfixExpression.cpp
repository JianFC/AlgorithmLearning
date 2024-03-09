#include <iostream>
#include <algorithm>
#include <stack>
#include <conio.h>
#define fp(i, l ,r) for(register int i=(l); i<=(r); i++) 
#define fd(i, l ,r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
stack<int> expr;
char ch;
int num;
int a, b;

int main(void) {
    cin >> ch;
    while (ch!='@') {
        switch(ch) {
            case '+': b = expr.top(); expr.pop(); a = expr.top(); expr.pop(); expr.push(a+b); break;
            case '-': b = expr.top(); expr.pop(); a = expr.top(); expr.pop(); expr.push(a-b); break;
            case '*': b = expr.top(); expr.pop(); a = expr.top(); expr.pop(); expr.push(a*b); break;
            case '/': b = expr.top(); expr.pop(); a = expr.top(); expr.pop(); expr.push(a/b); break;
            case '.': expr.push(num); num=0; break;
            default: num = num*10+ch-'0'; 
        }
        cin >> ch;
    }

    cout << expr.top();

    _getch();
    return 0;
}