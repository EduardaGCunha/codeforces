#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
sempre comeca no (0, 0) mod n
efetivamente os movimentos sao (a+i, b) e dps (x, b+i)
se individualemnte eu consigo chegar em todas as posicoes, ent talvez tbm consiga junto
se eu faco k movimentos, ent no total eu fiz (a*k mod n, b*k mod m) ne?
nn sei tanto a segunda parte considerando q eu inice com a, seria tipo b*(k-1) sla
parece coisa de coprimo 
*/

void solve(){
    int n, m, a, b; cin >> n >> m >> a >> b;
    if(gcd(n, m) > 2){
        cout << "NO\n";
        return;
    }else if(gcd(a, n) != 1){
        cout << "NO\n";
    }else if(gcd(b, m) != 1) cout << "NO\n";
    else cout <<"YES\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}