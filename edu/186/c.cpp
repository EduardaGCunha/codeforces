#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int arr[n], brr[n], crr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> brr[i];
    for(int i = 0; i < n; i++) cin >> crr[i];

    int cnt = 0, cnt2 = 0;
    for(int j = 0; j < n; j++){
        int pos = 1;
        for(int i = 0; i < n; i++){
            if(arr[(i+j)%n] >= brr[i]){
                pos = 0;
                break;
            }
        }
        if(pos) cnt++;
    }

    for(int j = 0; j < n; j++){
        int pos = 1;
        for(int i = 0; i < n; i++){
            if(brr[(i+j)%n] >= crr[i]){
                pos = 0;
                break;
            }
        }
        if(pos) cnt2++;
    }

    cout << n * cnt * cnt2 << endl;
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}