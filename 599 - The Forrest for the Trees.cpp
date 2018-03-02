#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cases=0; cases<t; cases++){
        vector <vector <int>> vec(26);
        int visited[26], vertices=0;
        memset(visited,-1, sizeof(visited));
        string s;
        while (cin >> s) {
            if (s[0] != '*')
            {
                vec[s[1] - 'A'].push_back(s[3] - 'A');
                vec[s[3] - 'A'].push_back(s[1] - 'A');
            }
            else {
                cin >> s;
                while (!s.empty()) {
                    visited[s[0] - 'A'] = 0;
                    vertices++;
                    //MAYBE LAST CHAR ERASE = SEG FAULT
                    s.erase(0, 2);
                }
                break;
            }
        }
        //IGNORE VISITED -1
        queue <int> Q;
        int root, acorn=0, tree=0;
        while (true){
            int count=0;
            for (int i=0; i<26; i++){
                if (visited[i] == 1) count++;
                if (visited[i] == 0)
                    root = i;
            }
            if (count == vertices) break;
            Q.push(root);
            visited[root] = 1;
            bool isolated= true;
            while(!Q.empty()){
                int v = Q.front();
                Q.pop();
                for (int i=0; i<vec[v].size(); i++){
                    isolated = false;
                    int to = vec[v][i];
                    if (visited[to] != 1){
                        visited[to] = 1;
                        Q.push(to);
                    }
                }
            }
            if (isolated) acorn++;
            else tree++;
        }
        printf("There are %i tree(s) and %i acorn(s).\n", tree, acorn);
    }
}
