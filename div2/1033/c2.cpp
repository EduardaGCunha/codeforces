#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n, k; cin >> n >> k;
    int tot = n*(n+1)/2;
    if(k < n || k > tot){
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> conn;
    vector<int> p(n+1);
    for(int i = 0; i < n; i++) {
		p[i] = i+1;
	}
    tot -= k;
    for(int i = n-1; i >= 0; i--){
        if(tot <= (p[i]-1)){
            p[i] -= tot;
            tot = 0;
        }else{
            tot -= (p[i]-1);
            p[i] = 1;
        }
        if(tot <= 0) break;
    }

    int rt = 0, mx = 0;
    for(int i = 0; i < n; i++){
        if(p[i] > mx){
            mx = p[i];
            rt = i;
        }
    }
    rt++;
    cout << rt << endl;
    for(int i = 0; i < n; i++){
        if(p[i] == i+1){
            if(i+1 == rt) continue;
            cout << i+1 << " " << rt << endl;
        }else cout << i+1 << " " << p[i] << endl;
    }
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}