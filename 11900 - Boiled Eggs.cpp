#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,p,q,temp;
    cin >> t;
    for (int loop=0; loop<t; loop++){
        multiset <int> setto;
        cin>>n>>p>>q;
        for (int i=0; i<n; i++){
            cin >> temp;
            setto.insert(temp);
        }
        int weight=0, eggs=0;
        for (int i=0; !setto.empty() && i<p; i++){
            weight += *setto.begin();
            setto.erase(setto.begin());
            if (weight > q) break;
            eggs++;
        }
        printf("Case %i: %i\n", loop+1, eggs);
    }
}
