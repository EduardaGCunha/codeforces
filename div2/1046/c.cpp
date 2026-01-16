#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 2e5+7;
int arr[MAXN];
deque<int> d[MAXN];

void solve(){
    int n; cin >> n;
    d[0].clear();
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        d[i].clear();
    }

    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; i++){
        d[arr[i]].emplace_back(i);
        dp[i] = dp[i-1];
        if(d[arr[i]].size() > arr[i]) d[arr[i]].pop_front();
        if(d[arr[i]].size() == arr[i]) dp[i] = max(dp[i], dp[d[arr[i]].front() - 1] + arr[i]);
    }

    cout << dp[n] << endl;
    
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}