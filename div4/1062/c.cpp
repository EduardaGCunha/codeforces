#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    int p = 0, ip = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i]&1) ip++;
        else p++;
    }

    if(p != 0 && ip != 0) sort(arr.begin(), arr.end());
    for(auto u : arr) cout << u << " ";
    cout << endl;
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}