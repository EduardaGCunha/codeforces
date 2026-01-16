#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

bool res(int a, int b){
	int k;
	bool pos = true;
	if(a < b) swap(a, b);
	if(!a || !b){
		if(a >= 3) pos = false;
	}else if(b == 1){
		if(a > 5) pos = false; 
	}else{
		k = a/b;
		//cout << k << endl;
		if(k >= 3) pos = false;
	}
	return pos;
}

void solve(){
	int a, b; cin >> a >> b;
	int c, d; cin >> c >> d;
	if(res(a, b) && res(c-a, d-b)) cout << "YES\n";
	else cout << "NO\n";
}

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}