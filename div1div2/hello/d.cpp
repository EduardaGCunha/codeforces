#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
	int n; cin >> n;
    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
    }

    vector<int> sz(n+1, 0);
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()){
        auto [d, v] = q.front(); q.pop();
        cout << d << " " << v << endl;
        sz[d]++;
        for(auto u : graph[v]){
            q.push({d+1, u});
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        cout << sz[i] << " ";
    }

    cout << ans + 1 << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}