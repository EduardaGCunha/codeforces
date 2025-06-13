#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    multiset<int> mx, my; 
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
        mx.insert(v[i].first);
        my.insert(v[i].second);
    }

    if(n == 1){
        cout << 1 << endl;
        return;
    }

    int ans = LLONG_MAX;
    for(int i = 0; i < n; i++){
        mx.erase(mx.find(v[i].first));
        my.erase(my.find(v[i].second));

        auto aux = mx.end();
        aux--;
        int xs = *(aux) - (int)*mx.begin()+1;
    
        aux = my.end();
        aux--; 
        int ys = (*aux) - (int) *my.begin()+1;

        mx.insert(v[i].first);
        my.insert(v[i].second);
        if(1LL * xs * ys == n-1){
            ans = min({ans, 1LL*(xs+1)*ys, 1LL*(ys+1)*xs});
        }else ans = min(ans, 1LL*xs*ys);
    }
    cout << ans << endl;
}

signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}