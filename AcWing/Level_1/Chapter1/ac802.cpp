#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;        //AcWing 802. 区间和

typedef pair<int, int> PII;

const int N = 300010;

int n, m;
int a[N], s[N];     //a[i]表示映射到i位置的原坐标上的值，s表示前缀和数组

vector<int> all;            //存储所有用到的下标
vector<PII> add, query;     //add存储所有插入操作，query存储所有查询曹祖

//去重
vector<int>::iterator unique(vector<int> &a) {  //unique函数  
    int j = 0;
    for (int i = 0; i < a.size(); i ++) 
        if (!i || a[i] != a[i - 1])
            a[j ++] = a[i];      //a[0] - a[j - 1] 存储所有不同的数

    return a.begin() + j;
}

//二分
int find(int x) {   //找到第一个大于等于x的位置
    int l = 0, r = all.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (all[mid] >= x) r = mid;
        else l = mid + 1;
    }

    return l + 1;   //+1映射到1, 2, 3, 4, ... n
}

int main(void) {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i ++) {
        int x, c;
        scanf("%d%d", &x, &c);
        add.push_back({x, c});
        all.push_back(x);
    }

    for (int i = 0; i < m; i ++) {
        int l, r;
        scanf("%d%d", &l, &r);
        query.push_back({l, r});
        all.push_back(l), all.push_back(r);
    }

    //去重
    sort(all.begin(), all.end());
    // all.erase(unique(all.begin(), all.end()), all.end());
    all.erase(unique(all), all.end());

    //处理插入操作
    for (auto item: add) {
        int x = find(item.first);   //x表示离散化后的坐标
        a[x] += item.second;
    }

    //预处理前缀和，all中存储所有用到的下标
    for (int i = 1; i <= all.size(); i++) s[i] = s[i - 1] + a[i];

    //处理查询
    for (auto item: query) {
        int l = find(item.first), r = find(item.second);    //下标映射
        printf("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}