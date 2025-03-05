#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        if(n == 1 && m == 1) cout << 1 << endl;
        else cout << (m-n) << endl;
    }
}