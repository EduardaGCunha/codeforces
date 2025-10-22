#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n, k; cin >> n >> k;
    vector<int> v;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int cnt = 1;
    for(int i = v.size()-1; i >= 0; i--){
        //cout << v[i] << " " << v[i]*cnt << endl;
        if((v[i]*cnt) > k) ans++;
        cnt *= 2;
    }
    cout << n-ans << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}