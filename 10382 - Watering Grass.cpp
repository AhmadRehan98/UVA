#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, l, w, radius, position;
    while (cin >> n >> l >> w) {
        map<double, double> mapie;
        for (int i = 0; i < n; i++) {
            cin >> position >> radius;
            double temp = pow(radius, 2) - (pow(w,2) / 4);
            if (temp >= 0) temp = sqrt(temp);
            else continue;
            mapie.insert(make_pair(position - temp, position + temp));
        }
        int sprinklers = 0;
        double last_end = 0, best_sprinklu = 0;
        if (mapie.begin()->first > 0) {
            cout << -1 << endl;
            continue;
        }
        while (!mapie.empty()) {
            while (!mapie.empty() && mapie.begin()->first <= last_end) {
                if (mapie.begin()->second > best_sprinklu)
                    best_sprinklu = mapie.begin()->second;
                mapie.erase(mapie.begin());
            }
            last_end = best_sprinklu;
            sprinklers++;
            if (mapie.begin()->first > last_end || last_end >= l)
                break;
        }
        if (last_end >= l)
            cout << sprinklers << endl;
        else cout << -1 << endl;
    }
}
