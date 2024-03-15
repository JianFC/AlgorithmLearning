#include <iostream>

using namespace std;     //AcWing 240. 食物链

const int N = 50010;

int n, m;
int p[N], d[N];

//维护每个结点到根结点的距离信息
int find(int x) {      

    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];    //p[x]记录了x节点的还未路径压缩时的根节点，递归结束走到此时
                            //d[p[x]]可能在上层递归作为子节点被更新过到根节点的距离
                            //所以需要在更新p[x]之前，先更新x节点到根节点的距离信息
        p[x] = t;
    }

    return p[x];
}

int main(void) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) p[i] = i;

    int res = 0;
    while (m --) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);

        if (x > n || y > n) res ++;
        else {
            if (t == 1) {
                int px = find(x), py = find(y);
                if (px == py && (d[x] - d[y]) % 3) res ++;      // x和y在同一个集合里，且d[x]和d[y]的距离差不为3时，该句话为假
                else if (px != py) {        //否则认为其为真，合并两个集合
                    p[px] = py;     //将x所在集合合并到y集合
                    d[px] = d[y] - d[x];    //如何规定d[px]的值？ 看图
                }
            }
            else if  (t == 2) {
                int px = find(x), py = find(y);
                if (px == py && (d[x] - d[y] - 1) % 3) res ++;  //在同一集合，判断是否为假，判断x和y的距离模3情况下是否为0
                else if (px != py) {    //合并两个集合
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];    
                }
            }
        }
    }

    printf("%d", res);

    return 0;
}
