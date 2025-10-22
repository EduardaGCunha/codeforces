#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'



void solve(){
    int n; cin >> n;
    int mx = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mx = max(mx, x);
    }
    cout << mx << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}