#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
	int n, k; cin >> n >> k;
    int cnt = 0, ans = 0;
    string s; cin >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') cnt++;
    }
    if(cnt <= k || n < 2*k) cout << "Alice\n";
    else cout << "Bob\n";

}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}