#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int pot[21], res[21];

void solve(){
	int n; cin >> n;
    int ans = 0;
    for(int i = 19; i >= 0; i--){
        int amnt = 0;
        if(n >= pot[i]){
            amnt = n/pot[i];
            ans += amnt*res[i];
            n -= amnt*pot[i];
            //cout << i << " " <<  pot[i] << " "  << n << endl;
            if(n == 0) break;
        }
    }
    cout << ans << endl;
}

signed main(){
	fastio;
	int t; cin >> t;

    int val = 3;
    pot[0] = 1;
    res[0] = 3;
    for(int i = 1; i <= 20; i++){
        pot[i] = val*pot[i-1];
    }

    for(int i = 1; i <= 19; i++){
        res[i] = pot[i+1] + i*(pot[i-1]);
    }
    //cout << res[0] << " " << res[1] << " " << res[2] << endl;
 
	while(t--){
		solve();
	}
}