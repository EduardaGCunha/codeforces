#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int s, m; cin >> s >> m;
    auto check = [&](int mid) -> int {
        int sum = s;

        for(int i = 63; i >= 0; i--){
            if(m&(1ll<<i)){
                int mx = sum >> i; 
                sum -= (min(mid, mx) << i);
            }
        }
        return sum <= 0;
    };

    int l = 0, r = 3e18;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid+1;
    }

    if(l > 2e18) cout << -1 << endl;
    else cout << l << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}