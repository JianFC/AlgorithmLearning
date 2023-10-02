#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;         //AcWing 845. 八数码

queue<string> q;
unordered_map<string, int> d;

int bfs(string state) {    
    d[state] = 0;
    q.push(state); 

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size()) {
        auto t = q.front(); q.pop();

        if (t == "12345678x") return d[t];

        int dist = d[t];
        int k = t.find('x');
        int x = k / 3, y = k % 3;

        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i]; 

            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                swap(t[a * 3 + b], t[k]);

                if (!d.count(t)) {
                    d[t] = dist + 1;
                    q.push(t);
                }

                swap(t[a * 3 + b], t[k]);   //恢复现场
            }
        }
    }

    return -1;
}

int main(void) {
    char s[2];
    string state;

    for (int i = 0; i < 9; i ++) {
        scanf("%s", s);
        state += *s;
    }

    cout << bfs(state);

    return 0;
}
