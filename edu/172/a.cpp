#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0, pos = 0;
    for(int i = 0; i <= n-4; i++){
        string t = s.substr(i, 4);
        if(t == "2025") ans = 1;
        else if(t == "2026"){
            ans = 0;
            break;
        }
    }

    cout << ans << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}