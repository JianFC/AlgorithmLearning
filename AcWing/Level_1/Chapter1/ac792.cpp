#include <iostream>
#include <vector>

using namespace std;

//判断A是否大于等于B
bool cmp(vector<int> &A, vector<int> &B) {      //AcWing 792. 高精度减法
    if (A.size() != B.size()) return A.size() > B.size();   //如果A和B位数不同
    else {      //位数相同
        for (int i = A.size() - 1; i >= 0; i --)     //从高位开始比较每一位的大小
            if (A[i] != B[i]) return A[i] > B[i];
    }

    return true;    //A = B
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;

    for (int i = 0, t = 0; i < A.size(); i ++) {     // A >= B,A.size >= B.size, t表示借位
        t = A[i] - t;
        if (i < B.size()) t -= B[i];    // t存储当前位的值应该是多少
        C.push_back((t + 10) % 10);     // t > 0, 则为t， t < 0, 则为t + 10
        if (t < 0) t = 1;       //存在借位
        else t = 0;         //不存在借位
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();     //处理前导0
    return C;
}


int main(void) {
    string a, b;
    vector<int> A, B, C;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');

    if (cmp(A, B)) C = sub(A, B);
    else C = sub(B, A), cout << "-";

    for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);

    return 0;
}