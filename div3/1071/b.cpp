#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<int> arr(n+2, 0), pref(n+2, 0), suf(n+2, 0);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    for(int i = 2; i <= n; i++){
        pref[i] += (pref[i-1] + abs(arr[i] - arr[i-1]));
    }

    for(int i = n-1; i >= 1; i--){
        suf[i] += (suf[i+1] + abs(arr[i] - arr[i+1]));
    }

    int ans = LLONG_MAX;

    ans = min({suf[2], pref[n-1]});
    for(int i = 1; i <= n; i++){
        ans = min(ans, suf[i+1] + pref[i-1] + abs(arr[i+1] - arr[i-1]));
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