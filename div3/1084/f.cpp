#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> val;
    int mx = 0;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        val.push_back({b, a});
        mx = max(mx, a);
    }
    sort(val.rbegin(), val.rend());
    priority_queue<int> q;
    vector<int> ans(n+1, 0);
    int sum = 0, idx = 0, cnt = 0;
    for(int i = n; i >= 0; i--){
    	while(idx < n && val[idx].first >= i){
            sum += val[idx].second;
            q.push(-val[idx].second);
            idx++;
        }
        while(q.size() > i+1){
            auto v = -q.top(); q.pop();
            sum -=v;
        }
        mx = max(mx, sum);
        while(q.size() > i){
            sum -= (-q.top());
            q.pop();
        }
        ans[i] = sum;
    }
    for(int i = 1; i <= n; i++) ans[i] = max(ans[i], ans[i-1]);
    
    while(m--){
    	int x, y; cin >> x >> y;
	    cout << max(mx, ans[y] + x) << " ";
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
