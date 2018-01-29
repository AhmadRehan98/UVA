#include <bits/stdc++.h>
using namespace std;
int f91(int n){
    if (n >= 101) return n-10;
    f91(f91(n+11));
}
int main() {
    int n;
    while (cin >> n && n!= 0){
        printf("f91(%i) = %i\n", n, f91(n));
    }
}