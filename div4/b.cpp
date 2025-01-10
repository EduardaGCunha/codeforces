#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < 4; j++) {
            if (row[j] == '#') {
                ans.push_back(j + 1); 
                break;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}
