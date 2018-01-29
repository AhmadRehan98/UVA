#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n;
    cin.ignore();
    getline(cin,s);
    for (int i=0; i<n; i++){
        double counter=0;
        map <string,int> mappie;
        while (true){
            getline(cin,s);
            if (s == ""){
                break;
            }
            counter++;
            mappie[s] += 1;
        }
        for (auto it = mappie.begin(); it != mappie.end(); it++){
            cout.precision(4);
            cout << fixed << it->first << " " << ((it->second)/counter)*100 << endl;
        }
        if (i<n-1) cout << endl;
    }
    return 0;
}