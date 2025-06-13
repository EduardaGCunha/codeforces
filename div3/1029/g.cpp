#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e18;

struct DSU{
    vector<int> p, r, low;
    DSU(int n) : p(n), r(n, 0), low(n, INF) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x){
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    int menor(){
        return low[find(0)];
    }

    void unite(int a, int b, int w){
        a = find(a), b = find(b);
        if(a == b){
            low[a] = min(low[a], w);
        }
        if(r[a] == r[b]) r[a]++;
        if(r[a] > r[b]){
            r[a]++;
            p[b] = a;
            //low[a] = min({low[a], low[b], w});
        }else{
            r[b]++;
            p[a] = b;
            //low[b] = min({low[b], low[a], w}); 
        }
    }
};

struct edges{
    int a, b, w;
    bool operator<(const edges &y) { return w < y.w; }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<edges> v;
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        a--, b--;
        v.push_back({a, b, w});
    }

    sort(v.begin(), v.end());
    DSU dsu(n);
    int ans = INF;
    for(int i = 0; i < m; i++){
        auto [a, b, w] = v[i];
        dsu.unite(a, b, w);
        int menor = dsu.menor(); 
        if(dsu.find(0) == dsu.find(n-1)){
            ans = min(ans, menor + w);
        }
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