#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,temp;
    while (cin >> n && n){
        cin.ignore();
        vector < vector <int> > vec(n+1);
        string s;
        while (getline(cin,s) && s[0] != '0') {
            string num="";
            int i;
            for (i=0; s[i] != ' '; i++)
                num+= s[i];
            int a = stoi(num);
            s.erase(0,i+1);
            while (s[0] != '0') {
                num="";
                for (i=0; s[i] != ' '; i++)
                    num+= s[i];
                s.erase(0,i+1);
                vec[a].push_back(stoi(num));
            }
        }
        cin >> m;
        for (int i=0; i<m; i++){
            cin >> temp;
            vec[0].push_back(temp);
        }
        bool used[101];
        queue <int> Q;
        while (vec[0].size()) {
            memset(used,0, sizeof(used));
            Q.push(vec[0][0]);
            int counter = 0;
            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                for (int i = 0; i < vec[v].size(); i++) {
                    int to = vec[v][i];
                    if (!used[to]) {
                        counter++;
                        used[to] = true;
                        Q.push(to);
                    }
                }
            }
            cout << n - counter;
            for (int i = 1; i <= n; i++) {
                if (!used[i]) cout << " " << i;
            }
            cout << endl;
            vec[0].erase(vec[0].begin(),vec[0].begin()+1);
        }
    }
}
