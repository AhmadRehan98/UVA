#include <bits/stdc++.h>
using namespace std;

int main() {
    map <string , string> mappie;
    string eng="00", foreign="00";
    while (eng != ""){
        getline(cin,eng);
        int x = eng.find(" ");
        foreign = eng.substr(x+1);
        eng = eng.substr(0 , x);
        mappie[foreign] = eng;
    }
    while (cin>>foreign){
        if (mappie.find(foreign) != mappie.end())
            cout << mappie[foreign] << endl;
        else cout << "eh" << endl;
    }
}