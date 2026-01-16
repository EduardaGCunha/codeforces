#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 998244353;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<pair<int, int>> conn;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        conn.push_back({a, b});
    }

    sort(conn.begin(), conn.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        return arr[a.second] < arr[b.second];
    });

    int ans = 0;
    //quantos acabam no vertice v com a soma X?
    vector<map<int, int>> dp(n);
    for(auto [u, v] : conn){
        //quantos terminam em u com soma prev?
        //arr[v] = prev + arr[u]
        //logo prev = arr[v] - arr[u]
        //existe uma tripla (prev, arr[v], arr[u])?
        int paths = dp[u][arr[v] - arr[u]];
        dp[v][arr[u]] = (dp[v][arr[u]] + paths + 1)%MOD;
        ans = (ans + paths + 1)%MOD;
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