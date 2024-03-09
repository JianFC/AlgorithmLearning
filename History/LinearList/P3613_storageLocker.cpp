#include <iostream>
#include <vector>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
const int maxn = 1e5+5;
// const int maxa = 1e5+5;
// int locker[maxn][maxa]
// 由分析可知locker为稀疏矩阵，使用二维数组来存储locker将浪费大量的存储空间，并导致内存空间溢出，
// 故此处使用两个vector创建动态数组来代替二维数组locker[maxn][maxa],以节约存储空间
vector<int> aID[maxn];
vector<int> aVal[maxn];
int n, q;
int op; 
int x, y, k;
int flag = 0;

int main(void) {
    cin >> n >> q;
    fp(i, 1, q) {
        cin >> op >> x >> y;
        flag = 0;
        int index;
        for (index=0; index<int(aID[x].size()); index++) {
            if (aID[x][index] == y) {
                flag = 1; break;
            }
        }
        if(op==1) {
            cin >> k;
            if (flag) aVal[x][index] = k;
            else {
                aID[x].push_back(y);
                aVal[x].push_back(k);
            } 
        }
        if(op==2) {
            if(flag) cout << aVal[x][index] << endl;
        }
    }

    _getch();
    return 0;
}