#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n >= 0){
    string ternary = "";
        while (n>0){
            ternary += to_string(n%3);
            n /= 3;
        }
        if (ternary.empty()) cout << 0;
        for (int i=ternary.length()-1; i>=0; i--){
            cout << ternary[i];
        }
        cout << endl;
    }
}
