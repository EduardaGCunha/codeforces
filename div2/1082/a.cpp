#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int a, b; cin >> a >> b;
    if(b > 0){
        a -= 2*b;
    }else if(b < 0){
        a -= 4*(-b);
    }
    if(a >= 0 && !(a%3)) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}