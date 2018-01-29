#include <bits/stdc++.h>
using namespace std;

int split(int big, int small){
    if (small > big) swap(big,small);
    if (small == 1 && big == 1) return 0;
    if (small == 1) return big-1;
    if (big % 2 == 0) return 2*split(big/2 , small) + 1;
    return split(big/2 , small) + split((big+1)/2 , small) + 1;
}

int main() {
    int n,m;
    while (cin >> n >> m){
        cout << split(n,m) << endl;
    }
}