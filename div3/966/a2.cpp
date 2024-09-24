#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        //cout << s[2] << endl;
        if((s[2]) == '0') cout << "NO" << endl;
        else if(s[0] == '1' && s[1] == '0' && s.size() >= 3){
            if(s[2] == '1' && s.size() == 3) cout << "NO" << endl;
            else cout << "YES" << endl;
        }else cout << "NO" << endl;
    }
} 