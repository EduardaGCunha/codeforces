#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(n&1){
        if(s[0] == 'b'){
            cout << "NO\n";
            return;
        }
        n--;
        s.erase(s.begin());
    }

    int pos = 1;
    for(int i = 0; i < n; i+=2){
        if(s[i] == 'a' && s[i+1] == 'a'){
            pos = 0;
            break;
        }
        if(s[i] == 'b' && s[i+1] == 'b'){
            pos = 0;
            break;
        }
    }
    if(pos) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}