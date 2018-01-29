#include <bits/stdc++.h>
using namespace std;
int main() {
    int n=1; bool line = false;
    while (cin >> n && n != 0){
        if (line) cout << endl;
        line = true;
        int id = 99999 / n;
        int d1=0,d2,d3,d4,d5;
            d5 = id % 10;
            id /= 10;
            d4 = id % 10;
            id /= 10;
            d3 = id % 10;
            id /= 10;
            d2 = id % 10;
            id /= 10;
            if (id > 0)
            d1 = id % 10;
        if (d1 != 0) d2 = 9;
        bool check = false;
        int num1[5]={0,1,1,1,1};
        int num2[5]={0,1,1,1,1};
        int fst_num, snd_num;
        for (int a=0; a<=d1; a++){
            num1[0] = a;
            for (int b=0; b<=d2;b++){
                if (b == a) continue;
                num1[1] = b;
                for (int c=0; c<=9; c++){
                    if (c == b || c == a) continue;
                    num1[2] = c;
                    for (int d=0; d<=9; d++){
                        if (c == d || d == b || d == a) continue;
                        num1[3] = d;
                        for (int e=0; e<=9; e++){
                            if (e == d || e == c || e == b || e == a) continue;
                            num1[4] = e;
                            fst_num = num1[4] + num1[3]*10 + num1[2]*100 + num1[1]*1000 + num1[0]*10000;
        for (int v=9; v>=0; v--){
            num2[0] = v;
            if (v == a || v == b || v == c || v == d || v == e) continue;
            for (int w=9; w>=0; w--){
                if (w == v || w==a || w==b || w==c || w==d || w==e) continue;
                num2[1] = w;
                for (int x=9; x>=0; x--){
                    if (x == w || x == v || x == a || x == b || x == c || x == d || x == e) continue;
                    num2[2] = x;
                    for (int y=9; y>=0; y--){
                        if (y == x || y == v || y == w || y == a || y == b || y == c || y == d || y == e) continue;
                        num2[3] = y;
                        for (int z=9; z>=0; z--){
                            if (y == z || z == x || z == w || z == v || z == a || z == b || z == c || z == d || z == e) continue;
                            num2[4] = z;
                            snd_num = num2[4] + num2[3]*10 + num2[2]*100 + num2[1]*1000 + num2[0]*10000;
                            if (snd_num % fst_num == 0 && snd_num/fst_num == n){
                                check = true;
                                if (num1[0] == 0)
                                    cout << snd_num << " / " << 0 << fst_num << " = " << n << endl;
                                    else
                                cout << snd_num << " / " << fst_num << " = " << n << endl;
                            }
                        }
                    }
                }
            }
        }
                        }
                    }
                }
            }
        }
    if (!check) cout << "There are no solutions for " << n << "." << endl;
    cout << endl;
    }
}
