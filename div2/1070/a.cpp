#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int arr[n];
    int mx = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x < mx) cnt++;
        mx = max(x, mx);
    }

    cout << cnt << endl;
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}