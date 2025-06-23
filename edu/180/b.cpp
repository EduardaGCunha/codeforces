#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)cin >> arr[i];

    for (int i = 0; i + 1 < n; i++) {
        if (abs(arr[i] - arr[i + 1]) <= 1) {
            cout << 0 << endl;
            return;
        }
    }

    for (int i = 0; i + 1 < n; i++) {
        int l = min(arr[i], arr[i + 1]);
        int h = max(arr[i], arr[i + 1]);

        if (i - 1 >= 0) {
            if (h >= arr[i - 1] - 1 && l <= arr[i - 1] + 1) {
                cout << 1 << endl;
                return;
            }
        }
        if (i + 2 < n) {
            if (h >= arr[i + 2] - 1 && l <= arr[i + 2] + 1) {
                cout << 1 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

signed main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
