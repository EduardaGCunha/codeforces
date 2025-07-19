#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n, k; cin >> n >> k;
    int arr[n];
    int mx = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        mx = max(arr[i], mx);
    } 
    
    int x = arr[k-1];
    sort(arr, arr+n);
    int ini;
    int pos = 1;
    for (int i = 0; i < n-1; i++){
        if (arr[i+1] > x){
            ini = i;
            break;
        } 
    }
    // cout << ini << endl;
    int top1 = 0;
    for (int i = ini; i < n-1; i++){
        // cout << water << endl;
        if (arr[i] == mx) break;

        int val = (arr[i+1] - arr[i]);
        top1 += val;
        if (top1 > arr[i]){
            pos = 0;
            break;
        }
    }
    if (pos) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}
