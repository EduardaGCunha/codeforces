#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
if this new sword we have can't attack anyone, then we must move to the next
how do we know it can't attack anyone?
use lowerbound to find the first it can attack
the opt
*/

struct val{
    int a, b; 
    bool operator<(const val &w) const {
        if(a != w.a){
            return a < w.a;
        }
        return b > w.b;
    }
};

void solve(){
	int n, m; cin >> n >> m;
    multiset<int> faca;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        faca.insert(x);
    }
    
    vector<int> brr(m);
    //vector<val> v(m);
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        brr[i] = x;
    }

    // for(auto u : faca){
    //     cout << u << endl;
    // }
    vector<pair<int, int>> v;
    vector<int> c;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        if(x > 0){
            v.push_back({brr[i], x});
        }else c.push_back(brr[i]);
    }

    sort(v.begin(), v.end());
    sort(c.begin(), c.end());
    int ans = 0;
    for(auto [a, b] : v){
        auto it = faca.lower_bound(a);
        if(it == faca.end()) continue;
        int x = *it;
        faca.erase(it);
        ans++;
        faca.insert(max(x, b));
    }

    //p cada
    for(auto u : c){
        //cout << u << " ";
        auto it = faca.lower_bound(u);
        if(it == faca.end()) continue;
        faca.erase(it);
        ans++;
    }
    //cout << endl;
    cout << ans << '\n';
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}