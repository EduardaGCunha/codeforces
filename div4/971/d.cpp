#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

void solve(){
    int n; cin >> n;
    map<int, int> mp0, mp1;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(b == 1) mp1[a]++;
        else mp0[a]++;
    }

    int ans = 0;
    //contando todos os triangulos normais
    for(auto u : mp0){
        if(mp1.count(u.first)){
            //cout << mp1.size() << " " << mp0.size() << endl;
            ans += mp1.size()-1 + mp0.size()-1;
        }
    }


    for(auto u : mp0){
        if(mp1.count(u.first-1) && mp1.count(u.first+1)){
            ans++;
        }
    }

    for(auto u : mp1){
        if(mp0.count(u.first-1) && mp0.count(u.first+1)){
            ans++;
        }
    }
    cout << ans << endl;

    
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}