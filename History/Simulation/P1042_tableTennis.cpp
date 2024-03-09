// P1042 [NOIP2003 普及组] 乒乓球
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <conio.h>
#include <cctype>
#include <math.h>
#include <string>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1e6+10;
char arr[maxn];  //arr存储每个球的胜负信息,
int cnt = 0;    //cnt是计数器
int w, l;   //w表示一局中华华的得分，l表示a对手的得分
 

int main(void) {
    char ch; cin >> ch;
    while(ch != 'E') {
       arr[cnt++] = ch;
       cin >> ch;
    }
    for (int i=0; 1; i++) {
       if (arr[i]=='W') w++;
       if (arr[i]=='L') l++;
       if ((w>=11||l>=11)&&(abs(w-l)>=2)) {
           cout << w << ":" << l << endl;
           w=0; l=0;
       }

       if (i==cnt-1 || cnt == 0) {  //注意此处条件不能合并到上一个if条件中，否则在示例WWWWWWWWWWW（11个W）E中不会输出最后的0:0
           cout << w << ":" << l << endl;
           break;
       }
    }

    cout << endl;
    w = l = 0;
    for (int i=0; 1; i++) {
        if (arr[i]=='W') w++;
        if (arr[i]=='L') l++;
        if ((w>=21||l>=21)&&(abs(w-l)>=2)) {
            cout << w << ":" << l << endl;
            w=0; l=0;
        }

        if (i==cnt-1 || cnt == 0){
            cout << w << ":" << l << endl;
            break;
        }
    }
    
    _getch();
    return 0;
}