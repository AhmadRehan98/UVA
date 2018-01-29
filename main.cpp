#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    long long counter=0;
    map <long long, long long> mappie;
    queue <long long> kyu;
    while (cin >> n){
        counter++;
        kyu.push(n);
        mappie[n] += 1;
    }
    while (kyu.size() > 0){
        if (mappie[kyu.front()] == 0){
            kyu.pop();
            continue;
        }
        cout << kyu.front() << " " << mappie.find(kyu.front()) -> second << endl;
        mappie[kyu.front()] = 0;
        kyu.pop();
    }
    return 0;
}