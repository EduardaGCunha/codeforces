#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s = "codeforces";
        string t; cin >> t;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i]) cnt++;
        }
        cout << cnt << endl;
    }
}