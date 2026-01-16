#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(min(x%k, abs(k-(x%k))));
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        b.push_back(min(x%k, abs(k-(x%k))));
    }
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