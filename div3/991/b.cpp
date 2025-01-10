#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n; 
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    
    if (sum % n != 0) {
        cout << "NO" << endl;
        return;
    }
    
    int target = sum / n;
    bool ans = true;
    for (int i = 1; i < n-1; i++){
            if (arr[i-1] < target){
                int temp = target-arr[i-1];
                 arr[i-1] =target;
                arr[i+1] -= temp;
            } 
            else if (arr[i-1] > target){
                int temp = arr[i-1]-target;
                arr[i-1] =target;
                arr[i+1] += temp;
            }
        }

         for (int i = 0; i < n-1; i++){
            if (arr[i] != arr[i+1]){
                ans = false;
                break;
            }
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
}

signed main() {
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
