#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

struct DSU{
    int n;
    vector<int> p, sz, cnt;
    void init(int _n){
        n = _n;
        p.resize(n);
        sz.resize(n);
        cnt.resize(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x){
        return (p[x] == x? x : find(p[x]));
    }

    int unite(int a, int b){
        //cout << a + 1 << " " << b+1 << " ";
        a = find(a);
        b = find(b);
        if(a == b) return 0;
        if(sz[a] < sz[b]) swap(a, b);
        int tira = sz[a]*(sz[a]-1)/2;
        int tirb = sz[b]*(sz[b]-1)/2;
        p[b] = a;
        sz[a] += sz[b];
        //cout << tira << " " << tirb << " " << sz[a]*(sz[a]-1)/2 << endl;
        return sz[a]*(sz[a]-1)/2 - tira - tirb; 
    }
};

void solve(){
    int n; cin >> n;
    int prev; cin >> prev;
    vector<vector<int>> v(n+1);
    for(int i = 0; i < n-1; i++){
        int x; cin >> x;
        int diff = abs(x - prev);
        v[diff].push_back(i);
        prev = x;
    }
    DSU dsu;
    dsu.init(n);
    int ans = 0;
    vector<int> res;
    for(int i = n-1; i >= 1; i--){
        for(auto idx : v[i]){
            ans += dsu.unite(idx, idx+1);
        }
        res.push_back(ans);
    }
    reverse(res.begin(), res.end());
    for(auto u : res) cout << u << " ";
    cout << endl;
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}