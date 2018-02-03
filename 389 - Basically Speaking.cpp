#include <bits/stdc++.h>
using namespace std;
int main() {
    int from,to,decimal;
    string n;
    char output[7];
    while (cin >> n >> from >> to){
        bool flag = false;
        decimal = 0;
        for (long long i=from; !n.empty(); i*= from){
            if (n[n.length()-1] <= '9') decimal += (n[n.length()-1] - '0')*(i/from);
            else {
                decimal += (n[n.length()-1] - 55)*(i/from);
            }
            n.erase(n.length()-1);
        }
        if (decimal == 0) {
            cout << "      0" << endl;
            continue;
        }
        memset(output,0, sizeof(output));
        for (int i=6; decimal>0; i--){
            if (i < 0) {
                cout << "  ERROR" << endl;
                flag = true;
            }
            int temp = decimal%to;
            if (temp == 10) output[i] = 'A';
            else if (temp == 11) output[i] = 'B';
            else if (temp == 12) output[i] = 'C';
            else if (temp == 13) output[i] = 'D';
            else if (temp == 14) output[i] = 'E';
            else if (temp == 15) output[i] = 'F';
            else output[i] = temp + 48;
            decimal /= to;
        }
        if (flag) continue;
        int index = 0;
        for (int i=0; i<7; i++){
            if (output[i] == 0) cout << " ";
            else {
                index = i;
                break;
            }
        }
        for (int i=index; i<7; i++){
            cout<<output[i];
        }
        cout << endl;
    }
}
