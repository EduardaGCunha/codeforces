#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int cnt = 0;
    for(int i = 2; i < n; i++){
        int mx = max(arr[i], arr[n-1] - arr[i]);
        //cout << mx << " " << arr[i] << " " << arr[n-1] - arr[i] << endl;
        int l = 0, r = i-1;
        while(l < r){
            if(arr[r] + arr[l] > mx){
                cnt += (r-l);
                r--;
            }else l++;
        }
        //cout << "iteracao i: " <<  cnt << endl;
    }
    cout << cnt << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}