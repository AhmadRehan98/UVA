#include <bits/stdc++.h>
using namespace std;
int main() {
    const double a = 32.2;
    bool first = true;
    int sce = 1;
    double arr[8];
    string s[8] = {"up hill", "well diameter", "water level", "bucket volume", "bucket ascent rate", "down hill", "required volume", "TIME REQUIRED"};
    while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> arr[6]){
        if (!first)  cout << endl;
        first = false;
        cout << "Scenario " << sce << ":" << endl;
        sce++;
        arr[7] = 0;
        double volume = arr[6];
        double height = arr[2];
        //copied times from another code
        double times = (int)ceil (volume/arr[3] - 0.00000001) ;
        while (times > 0){
                     //up time//down time //bucket descend time  //bucket ascend time
            arr[7] += arr[0] + arr[5] + (sqrt(2*height/(a*12))) + height/arr[4];
            //new L, height of water after the bucket is filled
            volume -= arr[3];
            height += (arr[3]*4*144*12/(arr[1]*arr[1]*M_PI));
            times--;
        }
        for (int i=0; i<8; i++){
            int digits;
            cout << "     ";
            if (arr[i] < 10) digits = 1;
            else if (arr[i] < 100) digits = 2;
            else if (arr[i] < 1000) digits = 3;
            else if (arr[i] < 10000) digits = 4;
            else if (arr[i] < 100000) digits = 5;
            else if (arr[i] < 1000000) digits = 6;
            else digits = 7;
            cout << s[i];
            for (int j=1; j<=23-s[i].length()-digits; j++){
                cout << " ";
            }
            cout << fixed << setprecision(2) << arr[i];
            if (i == 0 || i == 5 || i == 7) cout << " sec" << endl;
            else if (i == 1 || i == 2) cout << " in" << endl;
            else if (i == 3 || i == 6) cout << " cu ft" << endl;
            else if (i == 4) cout << " in/sec" << endl;
        }
    }
}