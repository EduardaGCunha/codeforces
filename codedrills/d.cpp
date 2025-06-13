#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> arr;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(x >= k) arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        int tot = arr.size();
        for(int i = 0; i < tot; i++){
            if(arr[i] >= k + ans) ans++;
        }
        cout << ans << endl;
    }

}