#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];


	int x; cin >> x;

	if(n == 1){
		if(arr[0] == x){
			cout << "YES\n";
		}else cout << "NO\n";
		return;
	}
	for(int i = 0; i < n-1; i++){
		int mn = min(arr[i], arr[i+1]);
		int mx = max(arr[i], arr[i+1]);
		if(x >= mn && x <= mx){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}