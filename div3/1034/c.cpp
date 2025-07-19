#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
	int n; cin >> n;
    int arr[n+1];
    vector<int> pref(n+1, INT_MAX), suf(n+2, 0);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pref[i] = min(pref[i-1], arr[i]);
    }
    
    for(int i = n; i >= 1; i--){
        suf[i] = max(suf[i+1], arr[i]);
    }

    for(int i = 1; i <= n; i++){
        if(arr[i] == pref[i] || arr[i] == suf[i]) cout << '1';
        else cout << '0';
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