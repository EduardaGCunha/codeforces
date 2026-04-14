#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x; cin >> x;
            freq[x]++;
        }
    }

    int v = (n-1)*n;
    bool pos = true;
    for(auto [a, b] : freq){
        if(b > v) pos = false;
    }
    if(pos) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}