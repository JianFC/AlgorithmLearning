#include <iostream>

using namespace std;        //AcWing 835. Trie字符串统计

const int N = 100010;

char str[N];
//son[N][26]第二维表示每个节点的最大子节点数量为26，具体实现时，存储儿子的下标
//cnt[i]以当前点i结尾的单词有多少个
//idx参考单链表中idx定义，当前用到了哪一个下标，idx为0的点，既是根节点，又是空节点（没有儿子的节点son值为0）
int son[N][26], cnt[N], idx;

//插入
void insert(char str[]) {   
    int p = 0;      //从根节点开始
    for (int i = 0; str[i]; i ++) {  //遍历字符串，字符串以0结束，所以可以作为判断条件
        int u = str[i] - 'a';   //下标映射
        if (!son[p][u]) son[p][u] = ++ idx;  //插入时，如果对应儿子不存在，则创建儿子
        p = son[p][u];      //p走到儿子节点
    }

    cnt[p] ++;   //插入完毕，更新cnt数组
}

//查找
int query(char str[]) {
    int p = 0;          //从根节点开始
    for (int i = 0; str[i]; i ++) {  //遍历字符串
        int u = str[i] - 'a';   //下标映射
        if (!son[p][u]) return 0;   //查找时对应儿子不存在，返回0
        p = son[p][u];      //p走到儿子节点
    }

    return cnt[p];      //返回cnt
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n --) {
        char op[2];
        scanf("%s%s", op, str);

        if (op[0] == 'I') insert(str);
        else printf("%d\n", query(str));
    }

    return 0;
}