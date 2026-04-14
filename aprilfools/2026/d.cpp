#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main(){
	fastio;
    string ans;
    int n; cin >> n;
	if(n ==1) ans= "walk";
    else if(n==2) ans = "no";
    else if(n == 3) ans = "no";
    else if(n==4) ans = "no";
    else if(n==5) ans = "yes";
    else if(n == 6) ans = "yes";
    else if(n == 7) ans = "backwards";
    else if(n == 8) ans = "7";
    cout << ans << endl;
}