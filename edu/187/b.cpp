#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n; cin >> n;
    string s = to_string(n);
    sort(s.begin()+1, s.end());

    int sum1 = 0, ans1 = 0;
    for(int i = 0; i < s.size(); i++){
        if(sum1 + (s[i]-'0') > 9){
            ans1 = s.size() - i;
            break;
        }
        sum1 += s[i]-'0';
    }


    int sum2 = 1, ans2 = 1; 
    for(int i = 1; i < s.size(); i++){
        if(sum2 + (s[i]-'0') > 9){
            ans2 = 1 + (s.size() - i);
            break;
        }
        sum2 += s[i]-'0';
    }

    //cout << min(ans1, ans2) << endl;
    //cout << ans1 << " " << ans2 << endl;
    cout << min(ans1, ans2) << endl;
}

signed main(){
	//fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}