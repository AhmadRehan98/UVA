#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,t;
    double time, fine;
    cin >> n;
    for (int cases=0; cases<n; cases++){
        cin >> t;
        vector <pair <double,int> > vectoro (t);
        for (int i=0; i<t; i++){
            cin >> time >> fine;
            vectoro[i].first = (time-fine)/time;
            vectoro[i].second = i+1;
        }
        sort (vectoro.begin(), vectoro.end());
        for (auto it=vectoro.begin(); it != vectoro.end(); it++){
            cout << it->second;
            if (it != prev(vectoro.end())) cout << " ";
        }
        cout << endl;
        if (cases < n-1) cout << endl;
    }
}
