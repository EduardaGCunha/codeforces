#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 70;
int cnt[MAXN][MAXN];

void solve(){
    int n, k; cin >> n >> k;
    int msb = 63 - __builtin_clzll(n);
    //cout << msb << endl;
    int ans = 0;
    for(int i = 0; i < msb; i++){
        for(int j = 0; j <= i; j++){
            if(i + j + 1 <= k){
                ans += cnt[i][j];
            }
        }
    }

    if(msb + 1 <= k) ans++;
    //cout << ans << endl;
    cout << (n - ans) << endl;
}

signed main(){
	fastio;
    for(int i = 0; i <= 64; i++){
        cnt[i][0] = 1; 
        for(int j = 1; j <= i; j++){
            cnt[i][j] = cnt[i-1][j-1] + cnt[i-1][j];
        }
    }
    int t; cin >> t;
	while(t--){
		solve();
	}
}