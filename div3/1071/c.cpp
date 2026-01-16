#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int arr[n];
    int mn = 1e9+7;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mn = min(mn, arr[i]);
    }

    int ans = 0, cur = 1e9+7;
    for(int i = 0; i < n; i++){
        if(arr[i] == mn) continue;
        cur = min(cur, arr[i] - mn);
    }
    ans = max(mn, cur);
    cout << ans << endl;
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}