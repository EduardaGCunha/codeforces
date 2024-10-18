#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2*(1e5);
vector<pair<int, int>> graph[MAXN];
int horse[MAXN];
const int INF = 1e12;
int n;

vector<int> dijkstra(int st){
    priority_queue<tuple<int, int, int>> pq; 
    vector<vector<int>> dist(2, vector<int>(n, INF));
    pq.push({0, 0, st});
    while(!pq.empty()){
        auto [dis, h, v] = pq.top(); pq.pop();
        dis = -dis;
        if(dist[h][v] < dis) continue;
        dist[h][v] = dis;
        h = (h | horse[v]);
        for(auto [u, c]: graph[v]){
            if(h) c /= 2;
            if(dist[h][u] > c + dis){
                dist[h][u] = c + dis;
                pq.push({-dist[h][u], h, u});
            }
        }
    }

    vector<int> d(n+1);
    for(int i = 0; i < n; i++){
        d[i] = min(dist[0][i], dist[1][i]);
    }

    return d;
}

signed main(){
    int t; cin >> t;
    while(t--){
        int m, h; cin >> n >> m >> h;
        for(int i = 0; i < n; i++){
            graph[i].clear();
            horse[i] = 0;
        }

        for(int i = 0; i < h; i++){
            int a; cin >> a;
            a--;
            horse[a]++;
        }

        while(m--){
            int a, b, c; cin >> a >> b >> c;
            a--, b--;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }

        vector<int> A = dijkstra(0);
        vector<int> B = dijkstra(n-1);

        int ans = INF;
        for(int i = 0; i < n; i++){
            ans = min(max(A[i], B[i]), ans);
        }

        if(ans >= INF){
            cout << -1 << endl;
        }else cout << ans << endl;

    }
}