#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    if(n == 2) cout << 2 << endl;
    else if(n == 3) cout << 3 << endl;
    else if(n&1) cout << 1 << endl;
    else cout << 0 << endl;
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}