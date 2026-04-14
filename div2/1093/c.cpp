#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e7;

void solve(){
    int p, q; cin >> p >> q;
    int tot = 2*q + p;
    tot = 2*tot + 1;
    for(int i = 2; i*i <= tot; i++){
        if(tot%(2*i + 1) == 0){
            int x = tot/(2*i+1);
            cout << i << " " << (x-1)/2 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
