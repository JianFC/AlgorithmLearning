//类约瑟夫问题
#include <iostream>
#include <algorithm>
#include <vector>
#include <conio.h>
#include <cstring>
#include <cstdio>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1e3+10;
struct point {
    int x, y;   //意义见题目
} poi[maxn];
int dx[9] = {0, 0, 0, 1, -1, 1, 1, -1, -1};
int dy[9] = {0, 1, -1, 0, 0, 1, -1, 1, -1};
int n;
int res[5]; //res[0-4]分别表示得分为0-4分的选址点个数

//检查(xx, yy)处是否有垃圾
inline bool check(int xx, int yy) {
    fp(i, 1, n) {
        if (poi[i].x == xx && poi[i].y == yy) return true;
    }
    return false;
}

int main(void) {
    cin >> n;
    fp(i, 1, n) cin >> poi[i].x >> poi[i].y;
    
    int xx, yy, flag, score;
    fp(i, 1, n) {
        xx = poi[i].x; yy = poi[i].y;
        flag = 1; 
        //检查上下左右是否有垃圾
        fp(j, 1, 4) {
            if (check(xx+dx[j], yy+dy[j])) continue;
            else {flag = 0; break;}
        }
        
        //计算得分
        if (flag) {
            score = 0;
            fp(j, 5, 8) {
                //cout << "(" << xx+dx[j] << ", " << yy+dy[j] << ")" << endl;
                //在算术表达式中使用三元运算符记得加括号提高三元运算符优先级，
                //否则由于三元运算符优先级较低，结果将可能出现问题!!!
                score = score + (check(xx+dx[j], yy+dy[j]) ? 1 : 0);    
            }
            //cout << i << " " << score << endl;
            res[score]++;
        }
    }

    fp(i, 0, 4) cout << res[i] << endl;

    _getch();
    return 0;
}
