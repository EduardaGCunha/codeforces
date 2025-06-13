#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
    int cnt = 0;
    int prev = 0;
    string ans = "NO\n";
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(i > 0 && prev == 0 && x == 0) ans = "YES\n";
        prev = x;
        cnt += x;
    }
    if(cnt == n) ans = "YES\n";
    cout << ans;
}

signed main(){
    fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}