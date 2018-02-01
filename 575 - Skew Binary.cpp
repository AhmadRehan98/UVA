#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    while (cin >> s && s != "0"){
        int n = s.length(), ans=0;
        for (int i=n-1; i>=0; i--){
            ans = ans + ( (s[i]-48)* round((pow(2,n-i)-1)) );
        }
        cout << ans << endl;
    }
}
