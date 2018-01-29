#include <bits/stdc++.h>
using namespace std;
set <int> primes;
void sieve () {
    bool check [1000006];
    memset(check, true, sizeof(check));
    check[0] = check[1] = false;
    for (int i=2; i<1000006; i++){
        if (check[i]){
            primes.insert(i);
            for (int j=2*i; j<1000006; j+=i){
                check[j] = false;
            }
        }
    }
}
int main() {
    int n,a,b;
    sieve();
    while (cin>>n && n!= 0){
        bool flag= false;
        for (auto it = primes.begin(); it !=primes.end(); it++){
            if (primes.find(n-*it) != primes.end()) flag = true;
            if (flag) {
                a = *it,  b=n-*it;
                break;
            }
        }
        if (!flag){
            cout << "Goldbach's conjecture is wrong." << endl;
            continue;
        }
        cout << n << " = " << a << " + " << b << endl;
    }
}