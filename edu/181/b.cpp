#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int a, b, k; cin >> a >> b >> k;
    int d = __gcd(a, b);

    int x = a/d, y = b/d;
    if(x <= k && y <= k) cout << 1 << endl;
    else cout << 2 << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}