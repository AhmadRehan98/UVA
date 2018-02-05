#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while (cin >> n && n){
        int row,column;
        double root = pow(2,log2(n)/2);
                int int_root = floor(root);
        while (true){
            if (int_root * int_root >= n && (int_root-1)*(int_root-1) <= n)
                break;
            else int_root++;
        }
        int index = n - (int_root-1)*(int_root-1);
        index %= int_root;
        if (!index) index = int_root;
        if (int_root%2==0){
            if((int_root-1)*(int_root-1) + int_root >= n){
                column=int_root;
                row=index;
            }
            else {
                column = int_root - index;
                row = int_root;
            }
        }
        else{
            if((int_root-1)*(int_root-1) + int_root >= n){
                column= index;
                row=int_root;
            }
            else{
                column=int_root;
                row=int_root - index;
            }
        }
        cout << row << " " << column << endl;
    }
}
