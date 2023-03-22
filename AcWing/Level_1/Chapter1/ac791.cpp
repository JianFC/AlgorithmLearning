#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {       //AcWing 791. 高精度加法
    vector<int> C;
    int t = 0;

    for (int i = 0; i < A.size() || i < B.size() || t; i++) {
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

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;
}