#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; bool buwl = false;
    deque <char> deq;
    deque <char> temp;
    while (cin >> s){
        for (int i=0; i<s.length(); i++){
            if (s[i] == '[') {
                buwl = true;
                continue;
            }
            else if (s[i] == ']') {
                buwl = false;
                continue;
            }
            if (buwl == false)
                deq.push_back(s[i]);
            else{
                while (i < s.length() && s[i] != ']' && s[i] != '['){
                    temp.push_back(s[i]);
                    i++;
                }
                i--;
                while (temp.size() > 0){
                    char c = temp.back();
                    deq.push_front(c);
                    temp.pop_back();
                }
            }
        }
        while (deq.size() > 0){
                cout << deq.front();
                deq.pop_front();
        }
       cout << endl;
    }
}
