#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cctype>
#include<cstdlib>
#include <conio.h>
using namespace std;
typedef long long ll;
template<typename T>inline void read(T &x){//模板输入输出优化
    x=0;T f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    x*=f;
}
template<typename T>inline void write(T x){
    if(x<0)putchar('-'),x*=-1;
    if(x>=10)write(x/10);
    putchar(x%10+'0');
}
const int maxa = 1e5+10;
int n,m,tot,now,a[maxa],l=0,r=0,mid;
inline bool judge(int x){//据某位叫x的dalao的观点，内联函数要快一点
	for(int i=1;i<=n;++i){//这里大家应该看得出，
                          //这个操作是在用贪心来看一看这个最大值是否能为x
		if(tot+a[i]<=x)tot+=a[i];
		else tot=a[i],now++;
	}
	if(now>=m)return true;
	else return false;
}
int main(){
	read(n);read(m);
	for(int i=1;i<=n;++i){
		read(a[i]);
		l=max(a[i],l);//l为区间最大数
		r+=a[i];//累加求r
	}
	while(l<=r){//二分模板
		mid=(l+r)>>1;
		tot=0,now=0;
		if(judge(mid))l=mid+1;
		else r=mid-1;
	}
	write(l);
    _getch();
	return 0;//完成！！！
}