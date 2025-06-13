#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 2e5+7;
vector<int> graph[MAXN];
int arr[MAXN], maxsum[MAXN], minsum[MAXN];

void dfs(int v, int p){
    for(auto u : graph[v]){
        if(u == p) continue;
        minsum[u] = min(arr[u], arr[u] - maxsum[v]);
        maxsum[u] = max(arr[u], arr[u] - minsum[v]);
        dfs(u, v);
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        graph[i].clear();
        arr[i] = 0;
        maxsum[i] = 0;
        minsum[i] = 0;
    }
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    minsum[0] = maxsum[0] = arr[0];
    dfs(0, -1);
    for(int i = 0; i < n; i++) cout << maxsum[i] << " ";
    cout << endl; 
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}