#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    int dup = 0;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    
    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i+1]) dup = 1;
    }
    
    if(dup) {
        cout << -1 << endl;
        return;
    }
    
    for (auto u : arr) cout << u << " ";
    cout << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
