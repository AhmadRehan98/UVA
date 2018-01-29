#include <bits/stdc++.h>
using namespace std;
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        int arr[100000];
        memset(arr,0,100000);
        long long sums[100000], total = 0;
        memset(sums,0,100000);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+100000);
        sums[0] = arr[100000-n];
        sums[1] = sums[0] + arr[100000-n+1];
        total = sums[1];
        for (int i = 2; i < n; i++) {
            sums[i] = sums[i - 1] + arr[100000-n+i];
            total += sums[i];
        }
        cout << total << endl;
    }
}