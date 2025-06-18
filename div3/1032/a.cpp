#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n, m; cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int r = arr[n-1] - arr[0];

    cout << min(abs(m - arr[0]) + r, abs(m - arr[n-1]) + r) << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}