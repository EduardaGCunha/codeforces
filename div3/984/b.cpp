#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        unordered_map<int, int> mp;
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            mp[a] += b;  
        }

        vector<int> v;
        for (const auto& u : mp) {
            v.push_back(u.second);
        }

        sort(v.rbegin(), v.rend());

        int ans = 0;
        for (int i = 0; i < min(n, (int)v.size()); i++) {
            ans += v[i];
        }

        cout << ans << endl;
    }
}
