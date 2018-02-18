#include <bits/stdc++.h>
using namespace std;
int arr[1000006];

int main() {
    int t,n,m,k;
    cin >> t;
    for (int loop=1; loop<=t; loop++){
        cin >> n >> m >> k;
        memset(arr,0,sizeof(arr));
        arr[0] = 1;    arr[1] = 2;     arr[2] = 3;
        for (int i=3; i<n; i++){
            arr[i] = ( arr[i-1] + arr[i-2] + arr[i-3])%m +1;
        }
        deque <int> DQ;
        map <int,int> freq;
        int smallest = 10000006;
        for (int i=0; i<n; i++){
            while (freq.size() == k){
                if (smallest > DQ.size())  smallest = DQ.size();
                if (DQ.front() <= k)       freq[DQ.front()]--;
                if (freq[DQ.front()] == 0) freq.erase(DQ.front());
                DQ.erase(DQ.begin());
            }
            DQ.push_back(arr[i]);
            if (arr[i] <= k && arr[i]) {
                freq[arr[i]]++;
            }
        }
        if (freq.size() == k){
            if (smallest > DQ.size()) smallest = DQ.size();
        }
        if (smallest == 10000006)
            printf("Case %i: sequence nai\n", loop);
        else
            printf("Case %i: %i\n", loop, smallest);
    }
}
