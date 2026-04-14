#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int m; cin >> m;
    int n = 3*m;
    int r = n, mid = n-1, l = 1;
    while(mid != l+1){
        cout << r << " " << mid << " " << l << " ";
        mid -=2;
        r -=2;
        l++;
    }
    cout << r << " " << mid << " " << l << " ";
    cout << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}