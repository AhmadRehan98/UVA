#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    set <string> setto;
    while (getline(cin,s)){
        for (int i=0; i<s.length(); i++){
            if ( (s[i] < 65 || s[i] > 90)  && (s[i] < 97 || s[i] > 122) && s[i] != ' ' ) {
                s.erase(i,1);
                i--;
            }
            if (s[i] >= 65 && s[i] <= 90) {
                s[i] = tolower(s[i]);
            }
        }
        while (s.length()>0){
            int space = s.find(" ");
            if (space != -1){
                setto.insert(s.substr(0,space));
                s.erase(0,space+1);
            }
            else {
                setto.insert(s.substr(0));
                s.clear();
            }
        }
    }
    while (!setto.empty()){
        string s = *setto.begin();
        if (s.find(" ") != -1){
            setto.erase(setto.begin());
            continue;
        }
        cout << s << endl;
        setto.erase(setto.begin());
    }
    return 0;
}