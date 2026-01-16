#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    char f = s[n-1];
    for(int i = 0; i < n-1; i++){
        if(s[i] != f) ans++;
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