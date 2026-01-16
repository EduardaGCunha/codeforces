#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int val[n];
    int ans = 1;
    for(int i = 0; i < n; i++) cin >> val[i];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(val[i] > x) ans += val[i] - x;
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