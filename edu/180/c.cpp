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
        for(int j = i+1; j < n; j++){
            int dif = 0;
            if(arr[n-1] - (arr[i] + arr[j]) >= (arr[j] - arr[i])) dif = arr[n-1] - (arr[i] + arr[j]);
            else dif = (arr[j] - arr[i]);
            int x = upper_bound(arr.begin(), arr.end(), dif)-arr.begin();
            if(x >= i) continue;
            else ans += (i - x);
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