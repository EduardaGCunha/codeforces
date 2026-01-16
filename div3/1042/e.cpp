#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
	int arr[n], brr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < n; i++) cin >> brr[i];
	
	int pos = 1;
	for(int i = 0; i < n-1; i++){
		if(arr[i] == brr[i]) continue;
		int v1 = arr[i]^brr[i+1];
		int v2 = arr[i]^arr[i+1];
		//cout << v1 << " " << v2 << endl;
		if(v1 == brr[i] || v2 == brr[i]) continue;
		pos = 0;
	}

	if(arr[n-1] != brr[n-1]) pos = 0;
	if(pos) cout << "YES\n";
	else cout << "NO\n";
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}
