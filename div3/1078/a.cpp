#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int pos1 = 0, pos2 = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 1) pos1 = 1;
        if(x == 67) pos2 = 1;
    }

    if(pos2) cout << "Yes\n";
    else cout << "No\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}