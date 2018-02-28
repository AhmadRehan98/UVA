#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,p;
    cin >> n;
    for (int cases=0; cases<n; cases++){
        cin >> p;
        cin.ignore();
        string s;
        int min = 1005;
        map <int,vector<int>> mappie;
        for (int i=0; i<p; i++){
            getline(cin,s);
            int neighbors=1;
            while (true){
                int index = s.find(" ");
                if (index != -1) {
                    neighbors++;
                    s.erase(0,index+1);
                }
                else break;
            }
            if (neighbors <= min) {
                mappie[neighbors].push_back(i+1);
                min = neighbors;
            }
        }
            int l = mappie.begin()->second.size();
            for (int j=0; j<l; j++){
                cout << mappie.begin()->second[j];
                if (j != l-1)
                    cout << " ";
            }
        cout << endl;
    }
}
