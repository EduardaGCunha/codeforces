#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)cin >> arr[i];

    int dec = 1, cres = 1;
    for(int i = 1; i < n; i++){
        if(abs(arr[i] - arr[i-1]) <= 1){
            cout << 0 << endl;
            return;
        }

        if(arr[i] >= arr[i-1]) dec = 0;
        else cres = 0;
    }

    if(cres || dec) cout << -1 << endl;
    else cout << 1 << endl;
}

signed main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
