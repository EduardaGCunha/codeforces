#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, l; cin >> n >> m >> l;
    vector<pair<int, int>> hurdles(n);
    for(int i = 0; i < n; i++) cin >> hurdles[i].first >> hurdles[i].second;
    
    vector<pair<int, int>> up(m);
    for(int i = 0; i < m; i++)cin >> up[i].first >> up[i].second;

    int h = 0, u = 0, ans = 0, k = 1;
    up.push_back({l, 0});
    priority_queue<int> pq; 
    while(h < n){
        while(up[u].first < hurdles[h].first){
            pq.push(up[u].second);
            u++;
        }
        while(k <= hurdles[h].second - hurdles[h].first + 1){
            if(pq.empty()){
                cout << -1 << endl;
                return;
            }
            k+= pq.top(); pq.pop();
            ans++;
        }
        h++;
        
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}