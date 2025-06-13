#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

/*
if ax + 1 < a2, then a2 is written to another arr, otherwise it stays in the same
since its ordered, all duplicates are meaningless and even if they are removed it doesnt change
*/

void solve(){
    int n; cin >> n;
    int ans = 1;
    int prev; cin >> prev;
    vector<int> v;
    v.push_back(prev);
    for(int i = 1; i < n; i++){
        int x; cin >> x;
        if(prev+1 >= x) continue;
        prev = x;
        v.push_back(x);
    }
    cout << v.size() << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}