#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e6;
int primos[MAXN];

vector<int> p;

void sieve(){
    for(int i = 0; i < MAXN; i++) primos[i] = 1;

    for(int i = 2; i < MAXN; i++){
        if(!primos[i]) continue;
        p.push_back(i);
        for(int j = i*i; j < MAXN; j += i){
            primos[j] = 0;
        }
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cout << p[i]*p[i+1] << " ";
    }
    cout << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
    sieve();
    // for(auto u : p) cout << u << " ";
    // cout << endl;
	while(t--){
		solve();
	}
}