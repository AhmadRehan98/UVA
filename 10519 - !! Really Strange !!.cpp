#include <bits/stdc++.h>
using namespace std;
int n[105], n2[105], ans[300];
void neg(int len, int arr[]){
    for (int i=0; i<len; i++){
        if (arr[i] < 0){
            arr[i] += 10;
            arr[i+1]--;
        }
    }
}

void mul(int len){
    for (int i=0; i<len; i++){
        for (int j=0; j<len; j++){
            ans[i+j] += n[i] * n[j];
            if (ans[i+j] > 9){
                ans[i+j+1] += ans[i+j] / 10;
                ans[i+j] = ans[i+j] % 10;
            }
        }
    }
}
void carry (int len){
    for (int i=0; i<len; i++){
        ans[i] = -n2[i];
        if (ans[i] > 9){
            ans[i+1] = ans[i] / 10;
            ans[i] = ans[i] % 10;
        }
    }
}
int main() {
    string s;
    bool flag = false;
    while(cin >> s) {
        int len = s.length();
        if (len == 1){
            if (stoi(s) == 0) {
                cout << 1 << endl; flag=true;
            }
            else if (stoi(s) == 1) {
                cout << 2 << endl; flag=true;
            }
            else if (stoi(s) == 2) {
                cout << 4 << endl; flag=true;
            }
            else if (stoi(s) == 3) {
                cout << 8 << endl; flag=true;
            }
        }
        if (flag){
            flag = false;
            continue;
        }
        memset(ans, 0, sizeof(ans));
        memset(n, 0, sizeof(n));
        memset(n2, 0, sizeof(n2));
        for (int i = len - 1; i >= 0; i--)
            n[len - i - 1] = n2[len - i - 1] = s[i] - 48;
        n2[0] -= 2;
        neg(len, n2);
        carry(len);
        mul(len);
        int index = -1;
        for (int i = 300; i >= 0; i--) {
            if (ans[i] != 0) {
                index = i;
                break;
            }
        }
        neg(index, ans);
        for (int i = 300; i >= 0; i--) {
            if (ans[i] != 0) {
                index = i;
                break;
            }
        }
        for (int i = index; i >= 0; i--) {
            cout << ans[i];
        }
        cout << endl;
    }
}
