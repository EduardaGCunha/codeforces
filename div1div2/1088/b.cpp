#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 676767677;

void solve(){
    int x, y; cin >> x >> y;
    int sum = abs(x-y);
    int ans = 0;
    if(sum){
        for(int i = 1; i * i <= sum; i++){
            if(!(sum%i)){
                //cout << i << " ";
                ans = (ans +1)%MOD;
                if(i*i != sum) ans = (ans +1)%MOD;
            }
            //cout << endl;
        }
    }
    if(!ans) ans = 1;
    cout << ans << endl;
    for(int i = 0; i < y; i++) cout << -1 << " ";
    for(int i = 0; i < x; i++) cout << 1 << " ";
    cout << endl;

}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}