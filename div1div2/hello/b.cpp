#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n, k; cin >> n >> k;
    vector<int> arr(n);
    vector<int> pres(n+2, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pres[arr[i]]++;
    }

    int i = 0;
    while(pres[i]) i++;
    cout << min(k-1, i) << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}