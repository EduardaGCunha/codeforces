#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int l = -1, r = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            if(l == -1) l = i;
            r = i;
        }
    }

    if(l == -1){
        cout << "0 0\n";
    }else if(l == r) cout << "1 1\n";
    else{
        cout << (r-l+2)/2 << " " << r-l+1 << endl;
    }
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}