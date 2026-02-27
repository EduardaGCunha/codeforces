#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(n&1){
        cout << "NO\n";
        return;
    }

    vector<char> st;

    for(auto u : s){
        if(!st.empty() && st.back() == u) st.pop_back();
        else st.push_back(u);
    }

    if(st.empty()) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}