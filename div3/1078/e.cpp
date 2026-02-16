#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9+7;
const int MAXN = 3e5+7;
int p[MAXN], visited[MAXN], ans[MAXN], res[MAXN];
vector<int> graph[MAXN];

/*
posso precalcular o resultado a partir do 1

*/

void dfs(int v){
    //cout << v << " ";
    int l = graph[v][0], r = graph[v][1];
    if(!l && !r){
        ans[v] = 1;
        return;
    }

    // for(auto u : graph[v]){
    //     dfs(u);
    // }
    dfs(l);
    dfs(r);
    ans[v] = (ans[l] + ans[r] + 3)%MOD;
}

void dfs2(int v){
    int l = graph[v][0], r = graph[v][1];
    if(!l && !r) return;
    res[l] = (res[v] + ans[l])%MOD;
    res[r] = (res[v] + ans[r])%MOD;
    dfs2(l);
    dfs2(r);
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        graph[i].clear();
        p[i] = 0;
        visited[i] = 0;
        res[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        int a, b; cin >> a >> b;
        graph[i].push_back(a);
        graph[i].push_back(b);
        if(a) p[a] = i;
        if(b) p[b] = i;
    }

    // for(int i = 0; i < n; i++){
    //     cout << "conexoes do " << i << endl;
    //     for(auto u : graph[v]){
    //         cout << u << " ";
    //     }
    //     cout << endl << endl;
    // }

    dfs(1);
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << res << " ";
    // }
    // cout << endl;
    res[1] = ans[1]%MOD;
    dfs2(1);
    for(int i = 1; i <= n; i++){
        cout << (res[i])%MOD << " ";
    }
    cout << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}