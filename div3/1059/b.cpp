#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'



void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int pos = 0;
    for(int i = 0; i < (1<<n); i++){
        string p = "", x = "";
        vector<int> ind;
        for(int j = 0; j < n; j++){
            if(i&(1<<j)){
                p += s[j];
                ind.push_back(j);
            }
            else x += s[j];
        }

        int dec = 1;
        int one = 0;
        for(int j = 0; j < p.size(); j++){
            if(p[j] == '1') one = 1;
            if(p[j] == '0' && one) {
                dec = 0;
                break;
            }
        }

        string t = x;
        reverse(t.begin(), t.end());
        if(x == t && dec){
            cout << ind.size() << endl;
            for(auto u : ind) cout << u+1 << " ";
            cout << endl;
            pos = 1;
            break;
        }
    }

    if(!pos) cout << -1 << endl;
    
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}