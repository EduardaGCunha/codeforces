#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<int> arr(n), c(n);
    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int tot = 0;
    for(int i = 0; i < n; i++){
        cin >> c[i];
        dp[i] = c[i];
        tot += c[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] <= arr[i]){
                dp[i] = max(dp[j] + c[i], dp[i]);
            }
        }
    }

    int ans = 1e18;
    for(int i = 0; i < n; i++){
        ans = min(tot - dp[i], ans);
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