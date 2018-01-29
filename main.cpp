#include <bits/stdc++.h>
using namespace std;
int even[8] = {2,4,6,8,10,12,14,16};
int odd[7] = {3,5,7,9,11,13,15};
bool used[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int n, counter=1;
void ring (vector <int> ways, int i){
    if (used[i]) return;
    used[i] = 1;
    ways.push_back(i);
    if (ways.size() == n){
        if (ways.back() + 1 == 9 || ways.back() + 1 == 15 || ways.back() + 1 == 21 || ways.back() + 1 == 25 ){
            used[i] = 0;
            return;
        }
        for (auto it = ways.begin(); it != ways.end(); it++){
            if (it != ways.begin()) cout << " ";
            cout << *it;
        }
        cout << endl;
    }
    if (i % 2 == 0){
        for (int k=0; k<(n-1)/2; k++){
            if (ways.back() + odd[k] == 9  || ways.back() + odd[k] == 15 || ways.back() + odd[k] == 21 || ways.back() + odd[k] == 25 )
                continue;
            ring (ways, odd[k]);
        }
    }
    else {
        for (int j=0; j<n/2; j++){
            if (ways.back() + even[j] == 9  || ways.back() + even[j] == 15 || ways.back() + even[j] == 21 || ways.back() + even[j] == 25 )
                continue;
            ring (ways, even[j]);
        }
    }
    used[i] = 0;
    return;
}
int main() {
    while (cin >> n){
        vector <int> ways;
        if (counter > 1) cout << endl;
        cout << "Case " << counter << ":" << endl;
        ring (ways, 1);
        counter++;
    }
    return 0;
}