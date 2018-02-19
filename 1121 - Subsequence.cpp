#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,s,temp;
    while (cin >> n >> s){
        deque <int> DQ;
        int min_length = n+1, sum=0;
        for (int i=0; i<n; i++){
            cin >> temp;
            DQ.push_back(temp);
            sum += temp;
            while (!DQ.empty() && sum >= s){
                if (min_length > DQ.size()){
                    min_length = DQ.size();
                }
                sum -= DQ.front();
                DQ.erase(DQ.begin());
            }
        }
        if (min_length == n+1) min_length = 0;
        cout << min_length << endl;
    }
}
