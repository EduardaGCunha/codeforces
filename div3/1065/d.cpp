#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n; cin >> n;
    int arr[n+1];
    int pref[n+2], suf[n+2];
    pref[0] = 1e9;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    for(int i = 1; i <= n; i++) pref[i] = min(pref[i-1], arr[i]);

    suf[n+1] = 0;
    for(int i = n; i >= 0; i--) suf[i] = max(suf[i+1], arr[i]);

    for(int i = 2; i <= n; i++){
        if(pref[i-1] > suf[i]){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}