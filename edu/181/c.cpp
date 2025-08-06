#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int aux(int dividendo){
    int ans = dividendo;
    vector<int> p = {2, 3, 5, 7};
    int n = 4;
    for(int mask = 1; mask < (1 << n); mask++){
        int prod = 1;
        for(int i = 0; i < n; i++){
            if(mask&(1<<i)) prod *= p[i];
        }
        int tot = __builtin_popcount(mask);
        int val = (dividendo/prod);
        if(tot&1) ans -= val;
        else ans += val; 
    }
    return ans;
}

void solve(){
	int l, r; cin >> l >> r;
    cout << aux(r) - aux(l-1) << endl;
    int ans = (r-l);
    vector<int> p = {2, 3, 5, 7};
    int n = 4;
    for(int mask = 0; mask < (1 << n); mask++){
        int prod = 1;
        for(int i = 0; i < n; i++){
            if(mask&(1<<i)) prod *= p[i];
        }
        int tot = __builtin_popcount(mask);
        int val = (r/prod - (l-1)/prod);
        if(tot&1) ans -= val;
        else ans += val; 
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