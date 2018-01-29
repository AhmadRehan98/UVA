#include <bits/stdc++.h>
using namespace std;
int arr[4510][4510];
int main() {
    int ans;
    bool rev = true;
    arr[1][1] = 1;
    for (int i=2; i<4505; i++) {
        arr[1][i] = arr[1][i-1];
        if (i % 2 != 0)
            arr[1][i] += (i-1)*2;
        else
            arr[1][i]++;
        arr[i][1] = arr[i-1][1];
        if (i%2 == 0)
            arr[i][1] = arr[i][1] + (i*2-2);
        else
            arr[i][1]++;
    }
    for (int j=2; j<4500; j++){
        for (int i=2; i<4500; i++){
            if (rev){
                arr[i][j] = arr[i+1][j-1] +1;
                rev = false;
                continue;
            }
            arr[i][j] = arr[i+1][j-1] - 1;
            rev = true;
        }
        if (rev) rev=false;
        else rev=true;
    }
    bool flag=false;
    int n;
    freopen("output.txt","w",stdout);
    while (cin>> n){
        for (int i=1; i<4500; i++){
            if (flag) break;
            for (int j=1; j<4500; j++){
                if (arr[i][j] == n){
                    cout << "TERM " << n << " IS " << i << "/" << j << endl;
                    flag = true;
                    break;
                }
            }
        }
        flag = false;
    }
}