#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n; cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    if(n == 2){
        cout << -1 << endl;
        return;
    }
    if(n == 3){
        cout << "1 3\n2 3\n";
        return;
    }
    if(n ==4){
        cout << "1 2\n1 3\n1 4\n";
        return;
    }
    
    vector<pair<int, int>> ans;
    ans = {{1,2}, {2, 3}, {3, 4}};
    for(int i = 5; i <= n-1; i++){
        ans.push_back({2, i});
    }
    ans.push_back({1, n});
    for(auto [a, b] : ans){
        cout << a << " " << b << endl;
    }
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}