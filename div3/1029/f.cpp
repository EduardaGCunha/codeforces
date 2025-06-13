#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;
const int MAXN = 2e5+7;
vector<int> graph[MAXN];
int sz[MAXN];

void dfs(int v, int p){
    sz[v] = 1;
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        sz[v] += sz[u];
    }
}

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        graph[i].clear();
    }
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int folha = 0, pos = 0;
    for(int i = 1; i < n; i++){
        if(graph[i].size() == 1) folha++;
        if(graph[i].size() == 3) pos = i;
    }
    if(folha > 2){
        cout << 0 << endl;
        return;
    }
    if(folha == 1){
        cout << fastexpo(2, n) << endl;
        return;
    }

    dfs(0, -1);
    //cout << "passou da dfs\n";
    vector<int> children;
    for(auto u : graph[pos]){
        children.push_back(sz[u]);
    }
    sort(children.begin(), children.end());

    int a = children[0];
    int b = children[1];
    //cout << a << " " << b << endl;
    int x, y;
    if(a < b){
        x = 2*a;
        y = 2*a + 1;
    } else {
        x = 2*a;
        y = 2*a;
    }

    int A = fastexpo(2, n - x);
    int B = fastexpo(2, n - y);
    //cout << A << " " << B << endl;
    cout << ((A + B)%MOD) << endl;
}

signed main(){
    //fastio;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
