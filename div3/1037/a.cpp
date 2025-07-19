#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	string s; cin >> s;
    int mn = 10;
    for(int i = 0; i < s.size(); i++){
        if(s[i] - '0' < mn){
            mn = s[i] - '0';
        }
    }
    cout << mn << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}