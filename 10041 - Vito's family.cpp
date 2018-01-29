#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, s, digit, mid_point;
    cin >> r;
    for (int i=0; i<r; i++) {
        cin >> s;
        int arr[s];
        int sum=0;
        for (int j=0; j<s; j++) {
            cin >> arr[j];
        }
        sort(arr,arr+s);
        for (int j=0; j<s; j++){
            sum += abs(arr[s/2] - arr[j]);
        }
        cout << sum << endl;
    }
}