#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, cases=1;
    while (cin >> n && n>0) {
        cout << "Case " << cases << ": " << ceil(log2(n)) << endl;
        cases++;
    }
}
