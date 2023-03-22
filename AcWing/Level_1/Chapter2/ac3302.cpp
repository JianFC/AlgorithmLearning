#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

const int N = 100010;

char str[N];
int num[N];
char op[N];
int tt1, tt2;

void eval() {       //AcWing 3302. 表达式求值
    int b = num[tt1--];
    int a = num[tt1--];
    char c = op[tt2--];

    int x = 0;
    if (c == '+') x = a+b;
    else if (c == '-') x = a-b;
    else if (c == '*') x = a*b;
    else if (c == '/') x = a/b;

    num[++tt1] = x;
}

int main(void) {
    scanf("%s", str);

    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

    for (int i=0; str[i]; i++) {
        auto c = str[i];

        if (isdigit(c)) {
            int x = 0, j = i;
            while (str[j] && isdigit(str[j])) 
                x = x*10+str[j++]-'0';

            num[++tt1] = x;
            i = j-1;
        }
        else if (c == '(') op[++tt2] = c;
        else if (c == ')') {
            while (op[tt2] != '(') eval();
            tt2--;
        }
        else {
            while (tt2 && op[tt2]!='(' && pr[op[tt2]]>=pr[c]) eval();
            op[++tt2] = c;
        }
    }

    while (tt2) eval();
    printf("%d", num[tt1]);

    return 0;
}
