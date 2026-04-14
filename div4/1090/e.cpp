#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans = max(ans, arr[i]^arr[j]);
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