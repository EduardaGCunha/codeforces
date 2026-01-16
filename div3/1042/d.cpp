#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
     int n; cin >> n;
     vector<vector<int>> g(n);
     for(int i = 0; i < n-1; i++){
	int a, b; cin >> a >> b;
   	a--, b--;
	g[a].push_back(b);
	g[b].push_back(a);
     }
     int tot = 0;
     for(int i = 0; i < n; i++){
	if(g[i].size() == 1) tot++;
     }
	
     int mx = 0;
     for(int i = 0; i < n; i++){
	int leaf = (g[i].size() == 1);
	for(auto u : g[i]){
	   if(g[u].size() == 1) leaf++;
	}
	mx = max(mx, leaf);
     }
     cout << tot - mx << endl;

}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}
