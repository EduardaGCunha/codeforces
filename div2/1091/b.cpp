#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, k; cin >> n >> k;
    int l = -1, r = 0;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int x; cin >> x;
    x--;
    int goal = arr[x];
    int cnt=0;
    for(int i = 0; i < x; i++){
        if(arr[i] != arr[i+1]) cnt++;
    }

    int cnt2 = 0;
    for(int i = x; i < n-1; i++){
        if(arr[i] != arr[i+1]) cnt2++;
    }
    if(arr[n-1] != goal) cnt2++;
    int ans = 0;
    ans = max(cnt, cnt2);
    if(ans&1) ans++;
    cout << ans << endl;

}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}