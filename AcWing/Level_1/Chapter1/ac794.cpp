#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;    //AcWing 794. 高精度除法

// A / b, 商是C，余数是r，r传递引用
vector<int> div(vector<int> &A, int &b, int &r) { 
    vector<int> C;  //C存储答案

    for (int i = A.size() - 1; i >= 0; i --) {   //从最高位开始处理
        r = r * 10 + A[i];  //模拟余数计算过程
        C.push_back(r / b);
        r %= b;
    }

    reverse(C.begin(), C.end());        //低位存低位，高位存高位，保证加减乘除输入输出格式统一
    while (C.size() > 1 && C.back() == 0) C.pop_back();     //去除前导0

    return C;
}

int main(void) {
    string a; int b;
    vector<int> A, C; int r = 0;    //r表示余数，最开始为0

    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');

    C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
    cout << endl << r;

    return 0;
}