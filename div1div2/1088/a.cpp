#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;    
    int x;
    for(int i = 0; i < n; i++) cin >> x; 
    if(n <= 2){
        cout << n << endl;
        return;
    }

    for(int i = 0; i < n; i++){
        cout << 2 << " ";
    }
    cout << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}