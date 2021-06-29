#include <iostream>
#include <conio.h>
typedef long long ll;

using namespace std;
const int maxn = 1e5+10;
int q[maxn] = {0};

int main(void){
    int n, m, k;
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", &q[i]);
    while (m--) {
        scanf("%d", &k);
        int l=1, r = n;
        // 从右向左二分
        while(l<r) {
            int mid = (l+r)>>1;
            if (q[mid]>=k) r = mid;
            else l = mid + 1;
        }

        if (q[l] != k ) cout << "-1 -1" << endl;
        else {
            cout << l-1 << " ";
            l = 1, r = n;
            //从左向右二分
            while (l<r) {
                int mid = (l+r+1)>>1;
                if (q[mid]<=k) l = mid;
                else r = mid-1;
            }
            cout << l-1 << " " <<endl;
        
        }

    }


    _getch();
    return 0;
}