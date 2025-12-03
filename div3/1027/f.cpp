#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e6+7;

vector<int> divi[MAXN];
int dp[MAXN];
int x, y, k;

int pd(int v){
    if(v == 1) return 0;
    if(v <= k) return 1;
    if(dp[v]) return dp[v];

    dp[v] = 1e9;
    for(auto u : divi[v]){
        if(u > k) break;
        dp[v] = min(dp[v], pd(v/u) + 1);
    }

    return dp[v];
}


void solve(){
    cin >> x >> y >> k;

    int rem = x / __gcd(x, y);
    int add = y / __gcd(x, y);

    int ans = pd(rem);

    for(int i = 0; i < MAXN; i++) dp[i] = 0;

    ans += pd(add);

    if(ans >= 1e9) cout << -1 << endl;
    else cout << ans << endl;
}

signed main(){
	fastio;
    for(int i = 2; i < MAXN; i++){
        for(int j = i; j < MAXN; j += i){
            divi[j].push_back(i);
        }
    }
	int t; cin >> t;
	while(t--){
		solve();
	}
} 