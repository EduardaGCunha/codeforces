#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
    int mn; cin >> mn;
    int pos = 1;
    for(int i = 0; i < n-1; i++){
        int x; cin >> x;
        if(x >=2*mn){
            pos = 0;
        }
        mn = min(mn, x);
    }
    if(pos) cout << "YES\n";
    else cout << "NO\n";
   
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}