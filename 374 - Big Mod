#include <bits/stdc++.h>
using namespace std;


long long power (long long b, long long p, int m){
    if (p == 0) return 1;
    if (p % 2 == 1)   return b%m * power(b%m ,p-1,m)%m;
    return power(b*b%m , p/2,m)%m;
}

int main() {
    int b,p,m;
    while (cin>>b>>p>>m){
        cout << power(b,p,m)<< endl;
    }
}
