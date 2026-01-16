#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(a == b && a == c && a == d) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}