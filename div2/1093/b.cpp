#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define int long long

void solve() {
    int n, m; cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int cur = 1, mx = 1;
    for (int i = 1; i < n; i++){
        if (arr[i] == arr[i-1]){
            cur++;
            mx = max(cur,mx);
        }
        else cur = 1;
    }
    if (mx < m) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    fastio;
    int t; cin >> t;
    while(t--) solve();
}
