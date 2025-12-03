#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
precalcular o xor dos dois
fazer alteracao se for alterar o xor do cara atual
*/

void solve(){
    int n; cin >> n;
    int arr[n+1], brr[n+1];
    int xor1 = 0, xor2 = 0;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    for(int i = 1; i <= n; i++) cin >> brr[i];

    int diff[n+1];
    int v = 0;
    for(int i = 1; i <= n; i++){
        diff[i] = arr[i] ^ brr[i];
        v ^= diff[i];
    }
    if(!v){
        cout << "Tie\n";
        return;
    }

    int msb = -1;
    for(int i = 33; i >= 0; i--){
        if((v >> i)&1){
            msb = i;
            break;
        }
    }

    int lst = -1;
    for(int i = 1; i <= n; i++){
        if((diff[i] >> msb)&1){
            lst = i;
        }
    }

    if(lst%2 != 0) cout << "Ajisai\n";
    else cout << "Mai\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}