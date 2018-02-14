#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n;
    cin >> t;
    for (int loop=0; loop<t; loop++){
        string s;
        cin >> n >> s;
        int crows=0, count=0;
        while (!s.empty()){
            if (*s.begin() == '.'){
                s.erase(s.begin());
                crows++;
                if (s.empty()) break;
                s.erase(s.begin());
                if (s.empty()) break;
                s.erase(s.begin());
            }
            else s.erase(s.begin());
        }
        printf("Case %i: %i\n", loop+1, crows);
    }
}
