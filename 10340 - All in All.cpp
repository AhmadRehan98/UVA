#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    while (cin >> s >> t){
        int chars=0, length = s.length();
        while (!s.empty() && !t.empty()){
            if (t[0] == s[0]){
                s.erase(s.begin());
                chars++;
            }
            t.erase(t.begin());
        }
        if (chars == length) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
}
