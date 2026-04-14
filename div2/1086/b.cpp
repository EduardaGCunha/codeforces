#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, k, p, m; cin >> n >> k >> p >> m;
    queue<pair<int, int>> q;
    priority_queue<pair<int, int>> pq; 
    p--, k--;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(i <= k){
            if(i == p) pq.push({0, -x});
            else pq.push({-1, -x});
        }else{ 
            if(i == p) q.push({0, x});
            else q.push({-1, x});
        }
    }

    int cur = 0, ans = 0;
    while(true){
        auto [win, v] = pq.top();
        v = -v;
        pq.pop();

        if(v <= 0) break; 
        if(cur + v > m) break;

        if(win == 0) ans++;  
        cur += v;

        q.push({win, v});
        auto [win1, v1] = q.front(); q.pop();
        pq.push({win1, -v1});
    }

    cout << ans << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}