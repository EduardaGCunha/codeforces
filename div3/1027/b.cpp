#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

/*
k good strings means  that there needs to be exactly k equal caracters and only that
since we only have 0 and 1
000000
there is no way this can have only 2 equal caracters 
so, for example, if I want k equal characters, I need to have at least k*2 equal characters, either 1 or 2
then, I need to have an equal amount of remaining 1s and 0s so that I can order them to be equal
6
4
1101011001
cnt1 = 6-2 -> 4 
cnt0 = 4 ->
11000 11110

*/
void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt1 = 0, cnt0 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') cnt0++;
        else cnt1++;
    }
    
    if(abs(n/2 - cnt1) <= k && (abs(n/2 - cnt1)%2 == (k%2))) cout << "YES\n";
    else cout << "NO\n";

}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}