#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,x;
    while (cin >> n >> m && n){
        multiset <int> knights, heads;
        int gold=0, kills = 0;
        for (int i=0; i<n; i++) {
            cin >> x;
            heads.insert(x);
        }
        for (int i=0; i<m; i++){
            cin >> x;
            knights.insert(x);
        }
        while (!heads.empty() && !knights.empty()){
            if (*heads.begin() <= *knights.begin()){
                kills++;
                gold += *knights.begin();
                heads.erase(heads.begin());
            }
            knights.erase(knights.begin());
        }
        if (kills == n) cout << gold;
        else cout << "Loowater is doomed!";
        cout << endl;
    }
}
