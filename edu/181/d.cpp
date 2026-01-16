#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 998244353;

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        res = (res * a)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}

void solve(){
    int x = fastexpo(3, MOD-2);
    int y = fastexpo(2, MOD-2);
    int v = (x*y)%MOD;
    v = (v*x)%MOD;
    int u = (2*x)%MOD;
    u = (((u*u)%MOD)*(2*y))%MOD;
    cout << (u + v)%MOD << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}