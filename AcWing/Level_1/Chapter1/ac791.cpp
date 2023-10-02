#include <iostream>
#include <vector>

using namespace std;    //AcWing 791. 高精度加法

vector<int> add(vector<int> &A, vector<int> &B) {       
    vector<int> C;      //存储答案
    
    int t = 0;  //t存储进位，初始为0
    for (int i = 0; i < A.size() || i < B.size() || t; i ++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    return C;
}

int main(void) {
    string a, b;
    vector<int> A, B, C;

    cin >> a >> b;      // a = "123456"

    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');    // A = [6, 5, 4, 3, 2, 1]
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');

    C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);

    return 0;
}