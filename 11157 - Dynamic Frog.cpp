#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,d;
    string s;
    cin >> t;
    for (int cases=0; cases<t; cases++){
        cin >> n >> d;
        int max_ray7=0, max_rag3=0;
        bool swap = false;
        int last_stone_ray7=0, last_stone_rag3=0;
        for (int i=0; i<n; i++){
            cin >> s;
            if (s[0] == 'B'){
                s.erase(0,2);
                if (stoi(s) - last_stone_rag3 > max_rag3) {
                    max_rag3 = stoi(s) - last_stone_rag3;
                }
                if (stoi(s) - last_stone_ray7 > max_ray7) {
                    max_ray7 = stoi(s) - last_stone_ray7;
                }
                last_stone_rag3 = stoi(s);
                last_stone_ray7 = stoi(s);
            }
            else if (s[0] == 'S'){
                s.erase(0,2);
                if (swap){
                    if (max_ray7 < stoi(s) - last_stone_ray7) {
                        max_ray7 = stoi(s) - last_stone_ray7;
                    }
                    last_stone_ray7 = stoi(s);
                    swap = false;
                }
                else{
                    if (max_rag3 < stoi(s) - last_stone_rag3) {
                        max_rag3 = stoi(s) - last_stone_rag3;
                    }
                    last_stone_rag3 = stoi(s);
                    swap = true;
                }
            }
        }
        max_rag3 = (max_rag3 < d - last_stone_rag3)? d-last_stone_rag3:max_rag3;
        max_ray7 = (max_ray7 < d - last_stone_ray7)? d-last_stone_ray7:max_ray7;
        printf("Case %i: %i\n", cases+1, (max_rag3 >= max_ray7)? max_rag3 : max_ray7);
    }
}
