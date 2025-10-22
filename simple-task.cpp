#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MASK = (1<<20)+7;
const int MAXN = 20;

vector<int> graph[MAXN];
int dp[MAXN][MASK];

int s;

int pd(int v, int mask){
    auto& p = dp[v][mask];

    if(p != -1) return p;

    int ans = 0;
    for(auto u : graph[v]){
        if(u == s && __builtin_popcount(mask) >= 3) ans++;
        if(u < s || (mask&(1<<u))) continue;
        int newmask = mask | (1<<u);
        ans += pd(u, newmask);
    }
    return p = ans;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        memset(dp, -1, sizeof(dp));
        s = i;
        int mask = (1 << i);
        ans += pd(s, mask);
    }
    cout << ans/2 << endl;

}

signed main(){
	fastio;
	int t= 1;
	while(t--){
		solve();
	}
}