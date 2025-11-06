#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void first(){
    int n; cin >> n;
    string t = "";
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        t += (x-1 + 'a');
    }
    cout << t << endl;
}

void second(){
    string s; cin >> s;
    vector<int> val;
    for(int i = 0; i < s.size(); i++){
        int x = (s[i]-'a')+1;
        val.push_back(x);
    }
    cout << val.size() << endl;
    for(auto u : val) cout << u << " ";
    cout << endl;
}

void solve(){
    string s; cin >> s;
    if(s == "first"){
        first();
    }else{
        second();
    }
}

signed main(){
	fastio;
	int t;
    t = 1;
	while(t--){
		solve();
	}
}