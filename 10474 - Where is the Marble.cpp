#include <bits/stdc++.h>
using namespace std;
int arr[10000];
int binary_search (int start , int end , int x){
    while (start < end){
        int mid = start + (end - start)/2;
        if (arr[mid] < x) start = mid+1;
        else end = mid;
    }
    if (arr[start] == x) return start+1;
    else return -1;
}
int main() {
    int n,q,x,y;
    for (int i=1; i<=65; i++){
        cin >> n >> q;
        if (n == 0 && q == 0) return 0;
        for (int j=0; j<n; j++){
            cin >> arr[j];
        }
        sort (arr,arr+n);
        cout << "CASE# " << i << ":" << endl;
        for (int j=0; j<q; j++){
            cin >> x;
            y = binary_search (0 , n-1 , x);
            if (y == -1) cout << x << " not found" << endl;
            else cout << x << " found at " << y << endl;
        }
    }
    return 0;
}