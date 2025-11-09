#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
	vector<int> o, e;
	int um = 0;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		if(x == 1) um = 1;
		else if(x&1) o.push_back(x);
		else e.push_back(x);
	}

	if(um){
		int f1 = -1;
		for(auto u : o){
			f1 = u;
			break;
		}

		for(auto u : e){
			f1 = u;
			break;
		}

		cout << 1 << " " << f1 << endl;
		return;
	}

	if(e.size() >= 2){
		cout << e[0] << " " << e[1] << endl;
	}else{
		n = o.size();

		if(e.size() == 1){
			int p = e[0];
			//int acho = 0;
			for(int i = 0; i < o.size(); i++){
				if(o[i] < p){
					int v = (p%o[i]);
					if(!(v&1)){
						cout << o[i] << " " << p << endl;
						return;
					}
				}else{
					int v = (o[i])%p;
					if(!(v&1)){
						cout << p << " " << o[i] << endl;
						return;
					}
				}
			}
			
		}

		if(o.size() <= 4e3){
			for(int i = 0; i < n; i++){
				for(int j = i+1; j < n; j++){
					int v = (o[j]%o[i]);
					if(!(v&1)){
						cout << o[i] << " " << o[j] << endl;
						return;
					}
				}
			}
			cout << -1 << endl;
		}else{
			for(int i = 0; i < n-1; i++){
				int v = (o[i+1]%o[i]);
				if(!(v&1)){
					cout << o[i] << " " << o[i+1] << endl;
					return;
				}
			}
			cout << -1 << endl;
		}
	}

}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}