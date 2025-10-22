#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
    string a; cin >> a;
    int m; cin >> m;
    string b; cin >> b;
    string c; cin >> c;
    string pref = "", suf = "";
    for(int i = 0; i < m; i++){
        if(c[i] == 'D') suf += b[i];
        else pref += b[i];
    }
    reverse(pref.begin(), pref.end());
    cout << pref << a << suf << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}