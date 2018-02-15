#include <bits/stdc++.h>
using namespace std;
char arr[10][10];
void fill(pair <int,int> pairo, int n){
    int i = pairo.first;
    int j= pairo.second;
    for (char alpha='A'; alpha<='Z'; alpha++){
        if (i>0) {
            if (arr[i-1][j] == alpha) continue;
        }
        if (i<n-1){
            if (arr[i+1][j] == alpha) continue;
        }
        if (j>0){
            if (arr[i][j-1] == alpha) continue;
        }
        if (j<n-1){
            if (arr[i][j+1] == alpha) continue;
        }
        arr[i][j] = alpha;
        return;
    }
}

pair <int,int> index_of_start(int n) {
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i>0 && arr[i][j] == '.') {
                if (arr[i-1][j] != '.') return make_pair(i,j);
            }
            if (i<n-1 && arr[i][j] == '.'){
                if (arr[i+1][j] != '.') return make_pair(i,j);
            }
            if (j>0 && arr[i][j] == '.'){
                if (arr[i][j-1] != '.') return make_pair(i,j);
            }
            if (j<n-1 && arr[i][j] == '.'){
                if (arr[i][j+1] != '.') return make_pair(i,j);
            }
        }
    }
    return make_pair(0,0);
}

bool is_complete(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (arr[i][j] == '.') return false;
        }
    }
    return true;
}

int main() {
    int t,n;
    cin>>t;
    for (int loop=0; loop<t; loop++){
        cin >> n;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }
        while (!is_complete(n)){
            fill(index_of_start(n), n);
        }
        printf("Case %i:\n", loop+1);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
}
