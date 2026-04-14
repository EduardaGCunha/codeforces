#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n = 7;
    vector<int> v;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int sum2 = v[6], sum1 = v[0];
    for(int i = 0; i < n; i++){
        if(i) sum1 -= v[i];
        if(i != 6) sum2 -= v[i];
    }
    cout << max(sum1, sum2) << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}