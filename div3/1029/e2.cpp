#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int arr[n], brr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> brr[i];
    vector<int> visited(n+1, 0);
    if(arr[n-1] == brr[n-1]){
        cout << n << endl;
        return;
    }

    int ans = -1;
    for(int i = n-2; i >= 0; i--){
        if(arr[i] == brr[i] || arr[i] == arr[i+1] || brr[i] == brr[i+1] || visited[arr[i]] || visited[brr[i]]){
            ans = i;
            break;
        }
        visited[arr[i+1]] = 1;
        visited[brr[i+1]] = 1;
    }
    if(ans == -1) cout << 0 << endl;
    else cout << ans+1 << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
