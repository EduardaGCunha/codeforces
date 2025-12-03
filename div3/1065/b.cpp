#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    if(arr[0] == -1 && arr[n-1] == -1){
        arr[0] = 0;
        arr[n-1] = 0;
    }else if(arr[0] == -1) arr[0] = arr[n-1];
    else if(arr[n-1] == -1) arr[n-1] = arr[0];

    cout << abs(arr[n-1] - arr[0]) << endl;
    for(int i = 0; i < n; i++){
        if(arr[i] == -1) arr[i] = 0;
        cout << arr[i] << " ";
    }
    cout << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}