#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n, k; cin >> n >> k;
    int arr[n+1], brr[n+1];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) cin >> brr[i];

    vector<vector<int>> dp(2, vector<int>(n+1, 0));
    int ans = -1e18;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        dp[0][i] = max(arr[i], dp[0][i-1] + arr[i]);
        dp[1][i] = max(max(0ll, dp[0][i-1]) + arr[i] + brr[i], dp[1][i-1] + arr[i]);
        if(k & 1) ans = max(ans, dp[1][i]);
        else ans = max(ans, dp[0][i]);
    }

    cout << ans << endl;
    
}

signed main(){
	fastio;
    int t;
    //t = 1;
    cin >> t;
	while(t--){
		solve();
	}
}