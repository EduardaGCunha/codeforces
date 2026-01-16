#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int a, b, n; cin >> a >> b >> n;
    int m = (a/b);
    if(n <= m) cout << 1 << endl;
    else{
        if(a == b) cout << 1 << endl;
        else cout << 2 << endl;
    }
}   

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}