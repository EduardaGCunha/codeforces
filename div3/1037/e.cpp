#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
    int pref[n], suf[n];
    for(int i = 0; i < n; i++) cin >> pref[i];
    for(int i = 0; i < n; i++) cin >> suf[i];

    int arr[n];
    for(int i = 0; i < n; i++){
        int x = pref[i], y = suf[i];
        arr[i] =  x*y/(__gcd(x, y));
    }

    int val = arr[0];
    for(int i = 0; i < n; i++){
        int cur = gcd(arr[i], val);
        if(cur != pref[i]){
            cout << "NO\n";
            return;
        }
        val = cur;
    }

    val = arr[n-1];
    for(int i = n-1; i >=0; i--){
        int cur = gcd(arr[i], val);
        if(cur != suf[i]){
            cout << "NO\n";
            return;
        }
        val = cur;
    }

    cout << "YES\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}