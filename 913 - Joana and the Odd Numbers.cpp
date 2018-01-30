#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while(cin>>n) {
        long long ans=0, mid=0;
        int line,pos;
        if (n == 1) {
            cout << 1 << endl;
        }
        line = n/2;
        if (line%2!=0){
            mid = (line+1)/2;
            mid *= 4;
            mid += ( (line/2)* (mid*2) );
            mid++;
        }
        else{
            mid = line*4 + 4;
            mid *= (line/2);
            mid++;
        }
        pos = (n+1)/2;
        ans = (n-pos)*2 + mid;
        ans = 3*ans - 6;
        cout << ans << endl;
    }
}
