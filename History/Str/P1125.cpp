// P1125 [NOIP2008 提高组] 笨小猴

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <conio.h>
#define fp(i, l, r) for(register int i=(l); i<=(r); i++)
#define fd(i, l, r) for(register int i=(l); i>=(r); i--)
typedef long long ll;

using namespace std;
char word[150];
int num[30] = {0};
int flag[30] = {0}; //指示num[i]对应的字符是否出现，为1出现，为0未出现
int maxx = 0, minn = 0x7fffffff;

//找素数奇葩组合解法，线性筛素数+二分搜索，时间复杂度O(n)+O(logn)
bool isPrime[300];
int Prime[300], cnt = 0;
inline void getPrime(int n) {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    fp(i, 2, n) {
        if(isPrime[i]) 
            Prime[++cnt] = i;
        
        for (int j=1; (j<=cnt)&&(i*Prime[j]<=n); j++) {
            isPrime[i*Prime[j]] = 0;
            if (i%Prime[j] == 0) 
                break;
        }
    }
}

inline bool bianrySearch(int x) {
    int low = 1, high = cnt, mid;
    
    while(low<=high) {
        mid =(low+high)>>1;
        if (Prime[mid] == x) return true;
        else if(Prime[mid] > x) high = mid-1;
        else low = mid + 1;    
    }
    return false;
}

//判断一个数是否是素数__正经做法
inline bool judgePrime(int x) {
    if (x==1 || x==0) return false;
    if (x==2) return  true; 
    //一个数若可以进行因数分解，那么分解时得到的两个数一定是一个小于等于sqrt(n)，一个大于等于sqrt(n)，
    //据此，上述代码中并不需要遍历到n-1，遍历到sqrt(n)即可，因为若sqrt(n)左侧找不到约数，那么右侧也一定找不到约数。
    for (int i=2; i*i<=x; i++) {    
        if (x%i == 0) return false;
    }
    return true;
}


inline bool prime(int x) {
    return true;
}

int main(void) {
    cin >> word;
    int len = strlen(word);
    for (int i=0; i<len; i++) {
        num[word[i]-'a'+1]++;
        flag[word[i]-'a'+1] = 1;
    }
    fp(i, 1, 26) {
        if (flag[i]) {
            maxx = max(maxx, num[i]);
            minn = min(minn, num[i]);
        }
    }

    int temp = maxx-minn;
    getPrime(300);
    if (bianrySearch(temp)) {
        cout << "Lucky Word" << endl << temp;
    } else {
        cout << "No Answer" << endl << 0;
    }

    _getch();
    return 0;
}
