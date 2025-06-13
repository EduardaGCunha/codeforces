#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, k; cin >> n >> k;
    int arr[n];
    int fst = -1, lst = -1;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] && fst == -1) fst = i;
        if(arr[i]) lst = i;
    }

    if(lst - fst + 1 <= k) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}