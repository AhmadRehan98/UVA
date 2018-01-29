#include <bits/stdc++.h>
using namespace std;
int arr1[50], arr2[50], arr3[50], maxi;
int power(string s, int d){
    if (d == 1){
        return maxi;
    }
    int n = s.length(); maxi=0;
    for (int i=0; i<n; i++){
        for (int j=0; arr2[j]!=-1; j++) {
            int mul = arr1[i] * arr2[j];
            mul += arr3[j];
            if (j+i>=maxi) {
                maxi = j+i;
                if (mul > 9) maxi++;
            }
            arr3[j+i] = mul%10;
            arr3[j+i+1] = (mul/10)%10;
        }
    }
    for (int i=maxi; i>=0; i--){
        arr2[i] = arr3[i];
    }
    memset(arr3, 0, sizeof(arr3));
        return power(s, d-1);
}
int main() {
    long long n, d;
    while(cin >> n >> d && n!= 0) {
        if (d==0) {
            cout << 1 << endl;
            continue;
        }
        if (d==1){
            cout << n << endl;
            continue;
        }
        string s = to_string(n);
        memset(arr1, -1, sizeof(arr1));
        memset(arr2, -1, sizeof(arr2));
        memset(arr3, 0, sizeof(arr3));
        int len = s.length();
        for (int i=len-1; i>=0; i--){
            arr1[len-1-i] = arr2[len-1-i] = s[i]-48;
        }
        maxi = 0;
        int index = power(s,d);
        for (int i=index; i>=0; i--){
            cout << arr2[i];
        }
        cout << endl;
    }
}