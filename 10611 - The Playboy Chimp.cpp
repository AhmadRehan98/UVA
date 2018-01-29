#include <bits/stdc++.h>
using namespace std;
long long arr[50000];
int binary_search_first (long long start, long long end, long long height){
    while (start < end){
        long long mid = start + (end - start)/2;
        if (arr[mid] < height) start=mid+1;
        else end = mid;
    }
    if (start-1 >= 0 && arr[start] >= height) return arr[start-1];
        //if Luchu is shorter than or equal to arr[start], return the tallest lady that is shorter than Luchu
    else if (start -1 >= 0 && arr[start] < height) return arr[start];
        //if Luchu is taller than arr[start], return arr[start], because she is the tallest lady that is shorter than him
    else return -1;
        //if start-1 < 0, if Luchu is shorter than the whole array, print X, there is no shorter lady
}
int binary_search_last (long long start, long long end, long long height, long long n){
    while (start < end){
        long long mid = start + (end-start+1)/2;
        if (arr[mid] > height) end = mid-1;
        else start = mid;
    }
    if (start+1 < n && height < arr[0]) return arr[start];
        // if Luchu is shorter than the shortest lady, return the shortest lady
    else if (start+1 < n) return arr[start+1];
        // if the binary search last algorithm didn't reach the tallest lady, return the shortest lady that is taller than Luchu,
        // because binary search last will always return the previous smallest element if "height" was not found
        // if height was found, return arr[start+1] as well
    else return -1;
    // if start+1 overextended the array, if Luchu is taller than the whole array, print X, there is no taller lady
}
int main() {
    long long n,q,height,temp;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> q;
    for (int i=0; i<q; i++){
        cin >> height;
        temp = binary_search_first(0, n-1, height);
        if (temp == -1) cout << "X ";
        else cout << temp << " ";
        temp = binary_search_last (0, n-1, height, n);
        if (temp == -1) cout << "X" << endl;
        else cout << temp << endl;
    }
    return 0;
}