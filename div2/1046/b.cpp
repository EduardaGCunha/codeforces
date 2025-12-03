#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'



void solve(){
    int n; cin >> n;
    int mn = LLONG_MAX, mx = LLONG_MIN;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        mn = min(x-y, mn);
        mx = max(x+y, mx);
    }

    /*
    mexer 2e9 pra esquerda e 2e9 pra cima pra garantir q a gente esteja no topo esquerdo
    */
    cout << "? L 1000000000\n";
    int d; cin >> d;
    cout << "? L 1000000000\n";
    cin >> d;

    cout << "? U 1000000000\n";
    cin >> d;
    cout << "? U 1000000000\n";
    cin >> d; //esse eh o d1

    /*
    aq estamos no Y - X + mn(xi - yi)
    */
    int eq1 = d - mn;
    
    //temos q mover pro ponto direito agr, ent vamos pra 4e9
    for(int i = 0; i < 4; i++){
         cout << "? R 1000000000\n";
         cin >> d; 
    }

    //caso do X + Y - mx(xi - yi)
    int eq2 = d + mx;

    //uso as equacoes p descobrir o valor de X + Y
    int y = (eq1 + eq2)/2 - 4e9;
    int x = (eq2 - eq1)/2;


    cout << "! " << x << " " << y << endl;
}

signed main(){
	//fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}