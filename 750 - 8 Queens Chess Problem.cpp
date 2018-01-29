#include <bits/stdc++.h>
using namespace std;
int SOLN; int flag;
int arr[8];
bool visited[8];
int total[17];
int dif[17];

bool check (int col, int row){
    if(visited[row-1] || dif[8+col-row] || total[col+row]) return false;
    return true;
}

void fun(int col){
    if (col == flag) {
        fun(col+1);
        return;
    }
    if (col == 8){
        if (SOLN <= 9) cout << " ";
        cout << SOLN << "     ";
        for (int i=0; i<8; i++){
            cout << " " << arr[i];
        }
        cout << endl;
        SOLN++;
        return;
    }
    for (int i=1; i<=8; i++){
        if (check(col, i)){
            arr[col] = i;
            dif[8+col-i] = true;
            total[col+i] = true;
            visited[i-1] = true;
            fun(col+1);
            dif[8+col-i] = false;
            total[col+i] = false;
            visited[i-1] = false;
        }
    }
}

int main() {
    int n, row, col;
    cin >> n;
    for (int i=0; i<n; i++){
        SOLN=1;
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        memset(dif, 0, sizeof(dif));
        memset(total, 0, sizeof(total));
        cout << "SOLN       COLUMN" << endl << " #      1 2 3 4 5 6 7 8" << endl << endl;
        cin >> row >> col;
        flag = col-1;
        visited[row-1] = true;
        dif[7+col-row] = true;
        total[col+row-1] = true;
        arr[col-1] = row;
        fun(0);
        if (i != n-1)   cout << endl;
    }
}
