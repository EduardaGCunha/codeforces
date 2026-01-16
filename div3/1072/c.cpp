#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'
int k;
map<int, int> mp;
int rec(int n){
    if(n < k) return INT_MAX;
    if(n == k) return 0;
    if(mp[n]) return mp[n];
    if(n == 1) return mp[n] = rec(n/2)+ 1;
    return mp[n] = min(rec(n/2) + 1, rec((n+1)/2) + 1);
}

void solve(){
    int n;
    cin >> n >> k;
    mp.clear();
    int v = rec(n);
    if(v >= INT_MAX) cout << -1 << endl;
    else cout << v << endl;
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}