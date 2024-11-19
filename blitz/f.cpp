#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string a; cin >> a;
        string s = "abc";
        int cnt = 0;
        for(int i = 0; i < 3; i++){
            if(s[i] != a[i]) cnt++;
        }
        if(cnt == 3) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}