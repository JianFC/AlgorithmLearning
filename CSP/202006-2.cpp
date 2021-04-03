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
struct proj{
    int index, value;   //意义见题目
    proj(int index, int value): index(index), value(value){}
};
vector<proj> vec[3];    //vec[1]表示u向量，vec[2]表示v向量
int n, a, b;    //意义见题目
int uind = 0, vind = 0; //u向量位置指针，v向量位置指针
ll res = 0;     //保存输出结果

int main(void) {
    int ind, val;
    cin >> n >> a >> b;
    //输入数据
    fp(i, 1, a) { cin >> ind >> val; vec[1].push_back(proj(ind, val)); }
    fp(i, 1, b) { cin >> ind >> val; vec[2].push_back(proj(ind, val)); }

    //双指针移动法
    while (uind<int(vec[1].size()) && vind<int(vec[2].size())) {
        if (vec[1][uind].index == vec[2][vind].index) {
            res += ll(vec[1][uind].value) * vec[2][vind].value;
            uind++; vind++;
        }
        else if (vec[1][uind].index < vec[2][vind].index) uind++;
        else vind++;
    } 
    
    // 以下为错误解法，可能导致数组越界
    // fp(i, 0, int(vec[1].size()-1)) {
    //     //双指针移动法
    //     //while (vec[2][vind].index < vec[1][uind].index) vind++; 
        
    //     if (vec[1][uind].index == vec[2][vind].index) {
    //         res += ll(vec[1][uind].value) * vec[2][vind].value;
    //         uind++; vind++;
    //     }
    //     else if (vec[1][uind].index > vec[2][vind].index) {i--; vind++; }
    //     else uind++; 
    //     //else uind++;    //此时vec[1][uind].index < vec[2][vind].index,uind应随i不断自增
    // }

    cout << res;

    _getch();
    return 0;
}
