#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, l , m, car;
    string pos;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> l >> m;
        l = l*100;
        int left=0, right=0, temp_left=0, temp_right=0, moves=0;
        for (int j=0; j<m; j++){
            cin >> car >> pos;
            if (pos == "left"){
                temp_left += car;
                if (temp_left >=l) {
                    left++;
                    temp_left = car;
                }
            }
            else if (pos == "right"){
                temp_right += car;
                if (temp_right >= l){
                    right++;
                    temp_right = car;
                }
            }
        }
        if (temp_right != 0) right++;
        if (temp_left != 0) left++;
        moves = min(left,right)*2;
        left -= moves/2;
        right -= moves/2;
        if (left != 0)
            moves += left*2 -1;
        moves += right*2;
        cout << moves << endl;
    }
    return 0;
}