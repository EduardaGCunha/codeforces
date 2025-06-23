#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n, m; cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int dx, dy, x, y; cin >> dx >> dy >> x >> y;
        int a = (dx*x)% m, b = (dy*y)% m;
        if(a < 0) a += m;
        if(b < 0) b+=m;
        if(a == b) ans++;
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