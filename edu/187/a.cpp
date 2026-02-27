#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, m, d; cin >> n >> m >> d;
    int mx = (d/m)+1;
    cout << (n+mx-1)/(mx) << endl;
}

signed main(){
	//fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}