#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e18;
const int MAXN = 300;
vector<pair<int, int>> graph[MAXN];

signed main(){
	fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i <= n; i++) graph[i].clear();
    
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    priority_queue<pair<int, int>> pq;
    vector<int> dist(n+1, INF);
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        d = -d;
        if(dist[v] < d) continue;
        for(auto [u, w] : graph[v]){
            if(dist[u] > d + w){
                dist[u] = d + w;
                pq.push({-dist[u], u});
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(dist[i] == INF) cout << -1 << endl;
        else cout << dist[i] << endl;
    }
}

