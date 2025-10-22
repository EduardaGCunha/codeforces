#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;

    vector<int> ans;
    int pot = 1;
    for(int i = 1; i <= 18; i++){
        pot *= 10;
        if((pot+1) > n) break;
        if(n%(pot+1) == 0){
            ans.push_back(n/(pot+1));
        }
    }
    if(ans.empty()) cout << 0 << endl;
    else{
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        for(auto u : ans){
            cout << u << " ";
        }
        cout << endl;
    }
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}