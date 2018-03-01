#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cases=0; cases<t; cases++){
        int n,m, temp;
        cin >> n >> m;
        int incident[n][m];
        memset(incident,0, sizeof(incident));
        bool flag =false;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> temp;
                if (temp)
                    incident[i][j] = 1;
            }
        }
        vector <set <int> > vec(n+1);
        int pushes=0;
        for (int j=0; j<m && !flag; j++){
            int start=0;
            for (int i=0; i<n; i++){
                if (start != -1 && start != 0 && incident[i][j]) {
                    int size = vec[start].size();
                    vec[start].insert(i+1);
                    pushes++;
                    if (size == vec[start].size()) flag = true;
                    start = -1;
                }
                else if (incident[i][j]) {
                    if (start == -1) flag = true;
                    start=i+1;
                }
            }
            if (start != -1 && start != 0) flag = true;
        }
        if (pushes != m) flag = true;
        if (flag) cout << "No\n";
        else cout << "Yes\n";
    }
}
