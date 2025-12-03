#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 998244353;

void solve(){
    int n; cin >> n;
    int arr[n];
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    vector<int> c;
    for(auto [_, u] : freq) c.push_back(u);

    sort(c.rbegin(), c.rend());

    int sz = c.size();
    vector<int> pfx(sz+1, 1), sfx(sz+1, 1);
    pfx[0] = c[0];
    for(int i = 1; i < sz; i++) pfx[i] = (pfx[i-1]*c[i])%MOD;
    
    for(int i = sz-1; i >= 0; i--) sfx[i] = (sfx[i+1]*(c[i]+1))%MOD;

    // for(int i = 0; i < sz; i++) cout << sfx[i] << " ";
    // cout << endl;

    int ans = pfx[sz-1];
    for(int i = 1; i < sz; i++){
        int v = (pfx[i-1]*sfx[i+1])%MOD;
        ans = (ans + v)%MOD;
    }

    //cout << ans << endl;

    int tot = c[0];
    vector<int> dp(tot+1, 0);
    dp[0] = 1;
    for(int i = 1; i < sz; i++){
        for(int j = tot; j >= 0; j--){
            if(!dp[j]) continue;

            int nxt = min(tot, j+c[i]);
            dp[nxt] = (dp[nxt] + dp[j]*c[i])%MOD;
        }
    }

    cout << (ans + dp[tot])%MOD << endl;

}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}