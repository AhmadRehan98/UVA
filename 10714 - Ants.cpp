#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, l, n, position;
    cin >> t;
    int fastest_all [t], slowest_all [t];
    for(int loop=0;  loop<t; loop++) {
        int fastest = 0, slowest = 0;
        cin >> l >> n;
        for(int i=0; i<n; i++) {
            cin >> position;
            int nearest_edge = position < l-position? position: l-position;
            int furthest_edge = l - nearest_edge;
            fastest = fastest < nearest_edge ? nearest_edge : fastest;
            slowest = slowest < furthest_edge? furthest_edge : slowest;
        }
        slowest_all[loop] = slowest;
        fastest_all[loop] = fastest;
    }
    for (int i=0; i<t; i++)
        cout << fastest_all[i] << " " << slowest_all[i] << endl;
}
