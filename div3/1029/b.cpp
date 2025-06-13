#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
se eu colocar o 1 por ultimo e ir crescendo, ent sempre o cara
de tras vai ser menor e o ultimo cara vai ser maior
ai eh so eu ficar tirando o penultimo cara
*/

void solve(){
    int n; cin >> n;
    for(int i = 2; i <= n; i++){
        cout << i << " ";
    }
    cout << 1 << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}