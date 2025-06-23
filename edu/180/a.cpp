#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
determinar se o ponto inicial q o b pode escolher tem como
*/
void solve(){
	int a, x, y; cin >> a >> x >> y;
    for(int i = 1; i <= 100; i++){
        if(abs(i - x) < abs(a - x) && abs(i - y) < abs(a - y)){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}