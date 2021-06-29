#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;
const int maxn = 1e5 + 10;

inline vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C; int t = 0;
    for (int i=0; i < int(A.size()) || i < int(B.size()); i++) {
        if (i < int(A.size())) t += A[i];
        if (i < int(B.size())) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(1);
    return C;
}


int main(void) {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = int(a.size() - 1); i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = int(b.size() - 1); i >= 0; i--) B.push_back(b[i] - '0');

    auto c = add(A, B);
    for (int i = int(c.size() - 1); i >= 0; i--) cout << c[i];

    _getch();
    return 0;
}