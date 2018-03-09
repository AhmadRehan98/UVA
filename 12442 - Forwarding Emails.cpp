#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n,u,v;
    cin >> t;
    for (int cases=1; cases<=t; cases++) {
        cin >> n;
        vector<vector<int> > vec(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> u >> v;
            vec[u].push_back(v);
        }
        bool used_roots[n+1] = {0};
        int cnt = 1, used[n+1] = {0};
        queue<int> Q;
        int max_comp = 0, ans=0, curr_root=0, lp = 1;
        while (true) {
            for (; lp <= n; lp++) {
                if (!used_roots[lp]) {
                    Q.push(lp);
                    used_roots[lp] = true;
                    used[lp]= cnt;
                    curr_root = lp;
                    break;
                }
            }
            if (Q.empty()) {
                printf("Case %i: %i\n", cases, ans);
                break;
            }
            int components = 1;
            while (!Q.empty()) {
                int v2 = Q.front();
                Q.pop();
                for (int i = 0; i < vec[v2].size(); i++) {
                    int to = vec[v2][i];
                    if (used[to] != cnt) {
                        used[to] = cnt;
                        used_roots[to] = true;
                        Q.push(to);
                        components++;
                    }
                }
            }
            if (components > max_comp) {
                max_comp = components;
                ans = curr_root;
            }
            cnt++;
        }
    }
}
