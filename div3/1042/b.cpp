#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    if(!(n&1)){
        for(int i = 0; i < n-2; i++){
            if(i&1) cout << 3 << " ";
            else cout << -1 << " ";
        }
        cout << "-1 2\n";
        return;
    }
    for(int i = 0; i < n; i++){
        if(i&1) cout << 3 << " ";
        else cout << -1 << " ";
    }
    cout << endl;
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}