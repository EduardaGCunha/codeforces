#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n, m; cin >> n >> m;
    int tot = (n*(n+1))/2;
    if(m < n || m > tot){
        cout << -1 << endl;
        return;
    }

    int rem = tot - m;
    vector<int> p(n+1, 1);
    iota(p.begin(), p.end(), 0);
    for(int i = n-1; i>= 0; i--){
        if(rem > p[i]){
            rem -= (p[i] - 1);
            p[i] = 1;
        }else{
            p[i] -= rem;
            rem = 0;
            break;
        }
    }

    int root = *max_element(p.begin(), p.end());

    for(int i = 0; i < n; i++){
        if(i == root) continue;
        if(p[i] < root){
            cout << i + 1 << " " << root << endl;
        }else cout << i + 1 << " " << p[i] << endl;
    }

}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
} 