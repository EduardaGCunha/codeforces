#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, x, y; cin >> n >> x >> y;
    string s; cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') cnt1++;
        else cnt2++;
    }

    int p[n];
    int tot = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        tot += p[i];
    }
    if((tot > x + y) || (!cnt2 && x < y + n) || (!cnt1 && y < x + n)){
        cout << "NO\n";
        return;
    }

    int a = 0, b = 0;
    for(int i = 0; i < n; i++){ 
        int win = p[i]/2 + 1;
        int lose = p[i] - win;
        if(s[i] == '0') a+= win;
        else b += win;
    }

    if(a > x || b > y) cout << "NO\n";
    else cout << "YES\n";
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}