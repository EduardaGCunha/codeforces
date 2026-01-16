#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<int> even;
    int mx = -1, cnt = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x&1){
            mx = max(mx, x);
            cnt++;
        }
        else even.push_back(x);
    }

    sort(even.rbegin(), even.rend());
    vector<int> pref(even.size() + 1, 0);
    for(int i = 1; i <= even.size(); i++){
        pref[i] += pref[i-1] + even[i-1];
        //cout << pref[i] << " ";
    }

    for(int i = 1; i <= n; i++){
        int mn = i - (int)even.size();
        int need = max(mn, 1LL);
        if(!(need&1)) need++;
        if(need > cnt || need > i){
            cout << "0 ";
            continue;
        }

        cout << mx + pref[i-need] << " ";
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