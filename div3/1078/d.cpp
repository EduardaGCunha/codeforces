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
    
    int prim = (arr[0] + arr[n-1])/(n-1);
    //cout << arr[0] + arr[n] << " " << (arr[0] + arr[n]/(n-1));
    cout << (arr[1] - arr[0]  + prim)/2 << " ";
    for(int i = 1; i < n-1; i++){
       int val = (arr[i+1] + arr[i-1] - 2 * arr[i])/2;
       //cout << arr[i+1] + arr[i-1] << " " << 2*arr[i] << " " << (arr[i+1] + arr[i-1] - 2 * arr[i]); 
        cout << val << " ";
    }

    cout << (prim - arr[n-1] + arr[n-2])/2 << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}