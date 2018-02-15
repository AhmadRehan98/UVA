#include <bits/stdc++.h>
using namespace std;
int main() {
    int l,g, x, r;
    while (cin >> l >> g && l){
        multimap <int,int> mappie;
        for (int i=0; i<g; i++){
            cin >> x >> r;
            mappie.insert(make_pair(x-r,x+r));
        }
        int last_end=0, best_gaso=0, stations=0;
        bool possible = true;
        while (!mappie.empty() && last_end < l){
            if (mappie.begin()->first > last_end) {
                possible = false;
                break;
            }
            while (!mappie.empty() && mappie.begin()->first <= last_end){
                if (mappie.begin()->second > best_gaso){
                    best_gaso = mappie.begin()->second;
                }
                mappie.erase(mappie.begin());
            }
            last_end = best_gaso;
            stations++;
        }
        if (possible && last_end >= l)
            cout << g-stations << endl;
        else cout << -1 << endl;
    }
}
