#include <iostream>
typedef long long ll;

using namespace std;
const int maxn = 1e5+10;
int q[maxn] = {0};

int main(void) {    //AcWing 789. 数的范围
    int n, m, k;
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", &q[i]);
    while(m--) {
        scanf("%d", &k);
        int l = 1, r = n;
        while (l<r) {
            int mid = (l+r)>>1;
            if (q[mid]>=k) r = mid;
            else l = mid+1;
        }

        if (q[l] != k) cout << "-1 -1" <<endl;
        else {
            cout << l-1 << " ";
            l = 1, r = n;
            while (l<r) {
                int mid = (l+r+1)>>1;
                if (q[mid]<=k) l = mid;
                else r = mid-1;
            }

            cout << l-1 << " " << endl;
        }
    }

    return 0;
}