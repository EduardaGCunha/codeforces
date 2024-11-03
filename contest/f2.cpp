#include<bits/stdc++.h>
using namespace std;

const int MAXN = 55;
vector<int> graph[MAXN+1];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //dist, node atual
    priority_queue<pair<int, int>> pq;
    pq.push({-1, 0});

    vector<int> dist(n, INT_MAX);
    dist[0] = 1;
    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        d = -d;
        if(dist[v] < d) continue;
        for(auto u : graph[v]){
            if(dist[u] > d + 1){
                dist[u] = d + 1;
                pq.push({-dist[u], u});
            }
        }
    }
    if(dist[9-1] == INT_MAX) cout << -1 << endl;
    else cout << dist[9-1] << endl;
}