#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ans = 0;
        for (int i = 0; i <=2 ; i++) {
            if (i > n) continue;
            ans += ((n-i)/15) + 1;
        }
        cout << ans << endl;
    }
}