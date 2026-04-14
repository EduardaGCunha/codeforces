#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<double> c(n), p(n);
    for(int i = 0; i < n; i++){
        cin >> c[i] >> p[i];
        p[i] = 1.0 - (p[i]/100.0);
    }

    // for(int i = 0; i < n; i++){
    //     cout << p[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << c[i] << " ";
    // }
    // cout << endl;

    double ans = 0.0;
    for(int i = n-1; i>=0;i--){
        //cout << p[i]*ans << " " << p[i]*ans + c[i];
        ans = max(p[i]*ans + c[i], ans);
        //cout << ans << " ";
    }
    //cout << endl;
    cout << fixed << setprecision(20) << ans << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}