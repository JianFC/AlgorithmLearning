// #include <iostream>

// using namespace std;

// const int maxn = 1e5+10;

// int head, e[maxn], ne[maxn], idx;

// //初始化
// void init(void){
//     head = -1, idx = 0;
// }

// //在head后插入一个点
// void add_to_head(int x) {
//     e[idx] = x, ne[idx] = head, head = idx, idx++;
// }

// //在第k个结点后插入一个结点
// void add(int x, int k) {
//     e[idx] = x, ne[idx] = ne[k], ne[k] = idx, idx++;
// }

// //删除第k个结点后面的结点
// void remove(int k) {
//     ne[k] = ne[ne[k]];
// }

// int main(void){
//     int m;
//     cin >> m;
    
//     init();
    
//     while(m--) {
//         int k, x;
//         char op;
        
//         cin >> op;
//         if (op == 'H') {
//             cin >> x;
//             add_to_head(x);
//         }
//         else if (op == 'D') {
//             cin >> k;
//             if (k==0) head = ne[head];
//             remove(k-1);
//         }
//         else {
//             cin >> k >> x;
//             add(x, k-1);
//         }
//     }
    
//     for (int i=head; i!=-1; i = ne[i]) cout << e[i] << " ";
//     cout << endl;
    
    
//     return 0;
// }

//*********************************栈和队列
// #include <iostream>

// using namespace std;

// const int maxn = 1e5+10;

// int stk[maxn], tt;

// //栈顶插入一个元素
// stk[++tt] = x;

// //判断是否为空
// if (tt>0) not_empty();
// else empty();

// //删除栈顶元素
// tt--;

// //取栈顶元素
// stk[tt];

// //**************************队列

// int q[maxn], hh, tt = -1;

// //队尾插入一个元素
// q[++tt] = x;

// //队头弹出一个元素
// hh++;

// //判空
// if (hh <= tt) not_empty();
// else empty();

// //取对头元素
// q[hh];
// //取对位元素
// q[tt];
//*********************************栈和队列


//**********************************单调队列
// #include <iostream>

// using namespace std;

// const int maxn = 1e6;
// int a[maxn], q[maxn], hh, tt = -1;

// int main(void) {
//     int n, k;
//     scanf("%d%d", &n, &k);
//     for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    
//     for (int i=1; i<=n; i++) {
//         if (hh <= tt && i-k+1 > q[hh]) hh++; //出队操作
        
//         while (hh <= tt && a[q[tt]] >= a[i]) tt--;
//         q[++tt] = i;
        
//         if ( i-k+1>=1 ) printf("%d ", a[q[hh]]);
//     }
//     puts("");
    
//     hh = 0, tt = -1;
//     for (int i=1; i<=n; i++) {
//         if (hh <= tt && i-k+1 > q[hh]) hh++; //出队操作
        
//         while (hh <= tt && a[q[tt]] <= a[i]) tt--;
//         q[++tt] = i;
        
//         if ( i-k+1>=1 ) printf("%d ", a[q[hh]]);
//     }
    
//     return 0;
// }
//***************************************















