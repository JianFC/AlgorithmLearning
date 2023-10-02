#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int> &A, int b) {    //AcWing 793. 高精度乘法
    vector<int> C;      //存储答案

    for (int i = 0, t = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();     //处理前导0
    
    return C;
}

int main(void) {
    string a; int b;
    vector<int> A, C;

    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');

    C = mul (A, b);

    for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);

    return 0;
}