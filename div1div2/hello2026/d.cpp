#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e9;

void solve(){
    int n; cin >> n;
    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<pair<int, int>> q;
    vector<int> dist(n+2, INF), sz(n+2, 0);
    dist[0] = 0;
    q.push({0, 0});
    int ans = 0;
    while(!q.empty()){
        auto [d, v] = q.front(); q.pop();
        sz[d]++;
        for(auto u : graph[v]){
            if(dist[u] > dist[v] + 1){
                dist[u] = dist[v] + 1;
                q.push({dist[u], u});
            }
        }
    }

    for(int i = 0; i < n; i++){
        dist[i] = INF;
        ans = max(ans, sz[i]);
    }

    q.push({0, 0});
    dist[0] = 0;
    while(!q.empty()){
        auto [d, v] = q.front(); q.pop();
        int cnt = 0;
        for(auto u : graph[v]){
            if(dist[u] > dist[v] + 1){
                dist[u] = dist[v] + 1;
                cnt++;
                q.push({dist[u], u});
            }
        }
        if(cnt == sz[d+1]){
            ans = max(ans, sz[d+1]+1);
        }
    }

    cout << ans << endl;
}

signed main(){
	fastio;
    int t;
    cin >> t;
	while(t--){
		solve();
	}
}