#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(s[n-1] == '0' && s[0] == '0'){
        s += s;
        n += n;
    }

    int mx = 0, cur = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            mx = max(mx, cur);
            cur = 0;
        }else cur++;
    }
    mx = max(mx, cur);
    cout << mx << endl;
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}