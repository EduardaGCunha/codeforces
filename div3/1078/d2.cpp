#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

using namespace std;

const int MAXN = 3e5+7;

void solve() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int tot = (arr[0] + arr[n-1])/(n-1);
    //cout << tot << endl;
    int prev = (arr[1] - arr[0] + tot)/2;
    cout << prev << " ";
    for(int i = 2; i < n; i++){
       int v = (arr[i] - arr[i-1] + tot)/2;
       cout << v - prev << " ";
       prev = v;
    }
    cout << tot - prev << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}