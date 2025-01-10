#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define int long long

signed main() {_
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int sum = 0;
        for (char c : s) {
            sum += c - '0';
        }
        vector<int> dp(9, 0);
        dp[sum % 9] = 1;
        for (char c : s) {
            int val = c - '0';
            vector<int> new_dp(dp);
            if (val == 2 || val == 3) {
                int sqr = val * val;
                for (int j = 0; j < 9; ++j) {
                    if (dp[j]) {
                        int new_j = (j - val + sqr + 9) % 9;
                        new_dp[new_j] = 1;
                    }
                }
            }

            dp = new_dp;
        }
        if (dp[0]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}