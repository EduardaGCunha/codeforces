#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
    int f, lst; cin >> f;
    for(int i = 0; i < n-1; i++){
        cin >> lst;
    }

    if(f == 0 && lst == 0) cout << "Bob\n";
    else cout << "Alice\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}