#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;

    int ans = 0;
    for(int i = 0; i <= n; i++){
        int g = i, v = n-i;
        if(!(g%2) && !(v%4)) ans++;
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