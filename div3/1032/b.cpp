#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
b + b  = s 
a + b + c = s
a + c = b
*/

void solve(){
	int n; cin >> n;
    string s; cin >> s;
    vector<int> freqr(26, 0), freql(26, 0);
    for(int i = 0; i < n; i++){
        freqr[s[i]-'a']++;
    }

    for(int i = 1; i <= n-2; i++){
        freql[s[i]-'a']++;
        freqr[s[i]-'a']--;
        if(freql[s[i]-'a'] > 1 || freqr[s[i]-'a'] > 0){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";

}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}