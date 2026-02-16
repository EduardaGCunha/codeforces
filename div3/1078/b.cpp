#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int arr[n+1];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++){
        int k = i;
        while(!(arr[i]&1)) arr[i]/=2;
        while(!(k&1))  k/=2;
        if(arr[i] != k){
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}