#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s, m; cin >> s >> m;

        int i = 0;
        int ans = 0;
        while(s[i] == m[i] && i < s.size() && i < m.size()){
            ans++;
            i++;
        }
        int x = ans;
        if(ans != 0) ans++;
        ans += (s.size() - x);
        ans += (m.size() - x);
        if(!ans) ans++;
        cout << ans << endl;
    }
}