#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,m,x;
    while (cin >> n >> m && n && m){
        map <long long , long long> mappie;
        int counter=0;
        for (int i=0; i<n+m; i++){
            cin >> x;
            mappie[x] += 1;
            if (mappie[x] > 1) counter++;
        }
        cout << counter << endl;
    }
    return 0;
}