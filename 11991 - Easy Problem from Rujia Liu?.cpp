#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m, temp, num, k;
    while (cin >> n >> m) {
        vector <vector <int> > freq(1000006);
        for (int i = 0; i < n; i++) {
            cin >> temp;
            freq[temp].push_back(i + 1);
        }
        for (int i = 0; i < m; i++) {
            cin >> k >> num;
            if (freq[num].size() >= k)
                cout << freq[num][k - 1] << endl;
            else
                cout << 0 << endl;
        }
    }
}
