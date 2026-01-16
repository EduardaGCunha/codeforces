#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int arr[n+1], pref[n+1], suf[n+1];

    pref[0] = 1e9;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pref[i] = min(pref[i-1], arr[i]);
    }

    suf[n] = arr[n];
    for(int i = n-1; i > 0; i--){
        suf[i] = max(suf[i+1], arr[i]);
    }

    // for(int i = 1; i <= n; i++){
    //     cout << pref[i] << " ";
    // }
    // cout << endl; 
    // for(int i = 1; i <= n; i++){
    //     cout << suf[i] << " ";
    // }
    // cout << endl;

    suf[0] = suf[1];
    pref[0] = pref[1];
    for(int i = 1; i <= n; i++){
        if(pref[i-1] > suf[i]){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    for(int i = 1; i <= n; i++){
        if(suf[i] != arr[i]){
            cout << arr[i] << " " << suf[i] << endl;
        }if(suf[i] != suf[i-1]) cout << pref[i-1] << " " << suf[i] << endl;
    }
}   

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}