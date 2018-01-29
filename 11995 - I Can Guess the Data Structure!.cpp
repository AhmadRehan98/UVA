#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, y;
    while (cin >> n) {
        bool st=true, qu=true, pqu=true;
        priority_queue <int> pri_que;
        queue <int> que;
        stack <int> stak;
        for (int i=0; i<n; i++){
            cin >> x >> y;
            if (x == 1) {
                pri_que.push(y);
                que.push(y);
                stak.push(y);
            }
            else {
                if (!stak.empty() && y == stak.top())
                    stak.pop();
                else st = false;
                if (!que.empty() && y == que.front())
                    que.pop();
                else qu = false;
                if (!pri_que.empty() && y == pri_que.top())
                    pri_que.pop();
                else pqu = false;
            }
        }
        if ((qu && pqu) || (st && pqu) || (qu && st)) cout << "not sure" << endl;
        else if (!(qu || st || pqu)) cout << "impossible" << endl;
        else if (st) cout << "stack" << endl;
        else if (qu) cout << "queue" << endl;
        else if (pqu) cout << "priority queue" << endl;
    }
}