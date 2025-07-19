#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n, k; cin >> n >> k;
    int ans = 0, cnt = 0;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> pref(n+1, 0);
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1] + arr[i-1];
    }

    int i = 0;
    while(i <= n-k){
        if(pref[i+k] - pref[i] == 0){
            ans++;
            i += k+1;
        }else i++;
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