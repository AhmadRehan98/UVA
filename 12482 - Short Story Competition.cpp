#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,l,c;
    string s="", temp;
    while(cin >> n >> l >> c ){
        for (int i=0; i<n; i++){
            cin >> temp;
            s += temp;
            if (i < n-1) s+= " ";
        }
        int pages=0;
        while (s.length() > c){
            int i = c;
            while (s[i] != ' ')
                i--;
            s.erase(0,i+1);
            pages++;
        }
        if (s.length() > 0) pages++;
        if (pages%l != 0) pages+= l;
        pages /= l;
        cout << pages << endl;
        s.erase();
    }
}
