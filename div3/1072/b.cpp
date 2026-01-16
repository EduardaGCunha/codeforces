#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int s, k, m; cin >> s >> k >> m;
    int v = m/k;
    if(v&1) s = min(s, k);
    cout << max(0LL, s - (m%k)) << endl;
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}