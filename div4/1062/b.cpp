#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a == b) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}