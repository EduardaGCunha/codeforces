#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e6+1;
const int MOD = 1e9+7;
 
int fat[MAXN], inv[MAXN];
 
int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}


void solve(){
	int a, b, k; cin >> a >> b >> k;
    int linha = (k*(a-1))%MOD+1;
    //cout << linha << endl;
    int comb = 1;  
    for(int i = 0; i < a; i++){
        comb = comb*((linha-i)%MOD)%MOD;
        comb = (comb*(fastexpo(i+1, MOD-2)))%MOD; 
    }
    int coluna = k*(b-1)%MOD; 
    coluna = (coluna*comb)%MOD + 1;
    //int comb = fat[linha%MOD]*inv[a];
    // int coluna = k*(b-1)*comb+1;
    cout << (linha%MOD) << " " << (coluna%MOD) << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}