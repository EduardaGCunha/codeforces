#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
maior bit significativo de b tem q ser maior q o maior bit significativo de a
ai eu faco
x = maior bit significativo - 1
a^x -> vai tirar todos os bits ativos de a
*/


void solve(){
    int a, b; cin >> a >> b;
    int x = (1LL << (__lg(a) + 1));

    if(a == b){
        cout << 0 << endl;
        return;
    }

    if(b >= x){
        cout << -1 << endl;
        return;
    }
    x--;
    cout << 2 << endl;  
    int x1 = (a^x);
    int x2 = b^(x);
    cout << x1 << " " << x2 << endl;

}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}