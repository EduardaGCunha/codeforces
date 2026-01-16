#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 998244353;

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (a*res)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return res;
}
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> segments(m+1);
    int tot = 1;
    for(int i = 0; i < n; i++){
        int l, r, a, b; cin >> l >> r >> a >> b;
        int prob = (a * fastexpo(b, MOD-2))%MOD;
        int nprob = (1 - prob + MOD)%MOD;
        tot = (tot * nprob)%MOD;
        int w = (prob * fastexpo(nprob, MOD-2))%MOD;
        segments[r].push_back({l, w});

    }
    vector<int> dp(m+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= m; i++){
        for(auto [l, w] : segments[i]){
            dp[i] = (dp[i] + dp[l-1]*w)%MOD;
        }
    }
    cout << (dp[m]*tot)%MOD << endl;
}

signed main(){
	fastio;
    int t;
    //cin >> t;
    t= 1;
	while(t--){
		solve();
	}
}