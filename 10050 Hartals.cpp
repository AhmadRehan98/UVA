#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, N, P, arr[105];
    bool bit[3655];
    cin >> T;
    for (int cases=1; cases<=T; cases++)
    {
        memset(bit, 1, sizeof(bit));
        scanf("%d", &N);
        scanf("%d", &P);
        for (int i=0; i<P; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i=0; i<P; i++)
        {
            int j=arr[i]-1;
            while(j <= N)
            {
                bit[j] = 0;
                j += arr[i];
            }
        }
        for (int i=5; i<N; i+=7)
        {
            bit[i] = 1;
            bit[i+1] = 1;
        }
        int ans = 0;
        for (int i=0; i<N; i++)
        {
            if (!bit[i])
                ans++;
        }
        printf("%d\n", ans);
    }
}
