#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0){
        int ones = 0;
        string parity="";
        while (n > 0){
            int temp = n%2;
            parity += to_string(temp);
            n /= 2;
        }
        cout << "The parity of " ;
        for (int i=parity.length()-1; i>=0; i--){
            cout << parity[i];
            if (parity[i] == '1') ones++;
        }
        cout <<" is "<< ones << " (mod 2)." << endl;
    }
}
