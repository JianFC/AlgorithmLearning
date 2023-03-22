#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_divisors(int x) {   //AcWing 869. 试除法求约数
    vector<int> res;

    for (int i=1; i<=x/i; i++) {
        if (x%i == 0) {
            res.push_back(i);
            //特判
            if (i != x/i) res.push_back(x/i);
        }
    }

    sort(res.begin(), res.end());

    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        int a;
        scanf("%d", &a);

        auto res = get_divisors(a);

        for (auto t: res) cout << t << " ";
        puts("");
    }

    return 0;
}