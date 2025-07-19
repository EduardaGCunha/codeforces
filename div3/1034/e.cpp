#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
    vector<int> cnt(n+2, 0), pref(n+2, 0), dif(n+2, 0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt[x]++;
    }

    // for(int i = 0; i <= n; i++){
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;

    int k = 0;
    for(int i = 0; i <= n; i++, k++){
        dif[cnt[i]]++;
        dif[n-i+1]--;
        //achei o mex
        if(!cnt[i]) break;
    }
    //cout << k << endl;


    for(int i = 0; i <= n; i++){
        if(i > 0) dif[i] += dif[i-1];
        cout << dif[i] << " ";
    }
    cout << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}