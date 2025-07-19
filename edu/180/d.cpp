#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 2e5+7;
vector<int> graph[MAXN];
vector<pair<int, int>> conn;

void dfs(int v, int p, int tog){
    for(auto u : graph[v]){
        if(u == p) continue;
        if(tog){
            conn.push_back({v, u});
        }else conn.push_back({u, v});
        dfs(u, v, !tog);
    }
}

void solve(){
	int n; cin >> n;
    conn.clear();
    for(int i = 0; i < n; i++){
        graph[i].clear();
    }
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    

    int pos = 0, a = -1, b = -1, rt = -1;
    for(int i = 0; i < n; i++){
        if(graph[i].size() == 2){
            a = graph[i][0];
            b = graph[i][1];
            rt = i;
            conn.push_back({b, i});
            conn.push_back({i, a});
            pos = 1;
            break;
        }
    }

    if(!pos || n <= 2){
        cout << "NO" << endl;
        return;
    }

    dfs(a, rt, 0);
    dfs(b, rt, 1);

    cout << "YES\n";
    for(auto [x, y] : conn){
        cout << x+1 << " " << y+1 << endl;
    }

}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}