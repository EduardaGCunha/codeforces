#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t; cin >> s >> t;
    int n = (int) s.size()-t.size();
    int sz = t.size();
    int ans = 0;
    for(int i = 0; i <= n; i++){
        //cout << i << " " << s.substr(i, sz) << endl;
        if(s.substr(i, sz) == t) ans++;
    }
    reverse(s.begin(), s.end());
    for(int i = 0; i <= n;i++){
        //cout << i << " " << s.substr(i, sz) << endl;
        //cout << s.substr(i, sz) << endl;
        if(s.substr(i, sz) == t) ans++;
    }
    cout << ans << endl;
}