#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e2;
int prime[MAXN];
vector<int> pr;

void sieve(){
    for(int i = 2; i < MAXN; i++){
        prime[i] = i;
    }

    for(int i = 2; i < MAXN; i++){
        if(prime[i] == i){
            pr.push_back(i);
            for(int j = i*i; j < MAXN; j+=i) prime[j] = i;
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(auto p : pr){
        int pos = 0;
        for(auto u : arr){
            if((u%p)){
                pos = 1;
                break;
            }
        }
        if(pos){
            cout << p << endl;
            return;
        }
    }
}

signed main(){
	fastio;
    int t; cin >> t;
    sieve();
	while(t--){
		solve();
	}
}