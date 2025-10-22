#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int digits[16];

 
void solve(){
	int n; cin >> n;
    int i = 1, pot = 1;
    if(n <= 9){
        cout << n << endl;
        return;
    }
    while(i < 16){
        if(n >= digits[i]){
			n -= digits[i];
		}else break;
        i++;
        pot *= 10;
    }
    //cout << n/i <<" " << i << endl;
    int lst = (n/i)+pot;
	cout << lst << endl;
}

signed main(){
	fastio;
	int t; cin >> t;

	int pot = 10;
    digits[1] = 10;
	for(int i = 2; i < 16; i++){
		digits[i] = (10*pot - pot)*i; 
		pot *= 10;
	}
	cout << digits[1] << " " << digits[2] << " " << digits[3] << endl;
	while(t--){
		solve();
	}
}