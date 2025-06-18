#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*

*/

int dp[11][2][2];
int n;
string s, k;

int pd(int idx, int cl, int cr){
    if(idx == n) return 0;
    if(dp[idx][cl][cr] != -1) return dp[idx][cl][cr];
    int ans = 1e18;
    for(int i = 0; i <= 9; i++){
        if(s[idx]-'0' > i && !cl) continue;
        if(k[idx]-'0' < i && !cr) continue;
        int cur = (s[idx] == i+'0') + (k[idx] == i+'0') + pd(idx+1, (cl | (i  > s[idx]-'0')), (cr | (i < k[idx]-'0')));
        ans = min(cur, ans);
    }
    return dp[idx][cl][cr] = ans;
}

void solve(){
	cin >> s >> k;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    cout << pd(0, 0, 0) << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}