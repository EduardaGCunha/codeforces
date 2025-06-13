#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n+1];
        int ans = LLONG_MAX;
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        for(int i = 0; i < n; i++){
            int r = i;
            while(r+1 < n && arr[i] == arr[r+1]) r++;
            ans = min(ans, (i+n-r-1)*arr[i]);
            i = r; 
        }
        cout << ans << endl;
    }
}