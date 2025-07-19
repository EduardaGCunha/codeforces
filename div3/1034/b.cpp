#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n, j, k; cin >> n >> j >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(k >= 2){
        cout << "YES\n";
        return;
    }
    int val = arr[j-1];
    sort(arr, arr+n);
    if(val < arr[n-1]) cout << "NO\n";
    else cout << "YES\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}