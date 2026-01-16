#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int powers[19];

void pten(){
    powers[0] = 1;
    for(int i = 1; i <= 18; i++){
        powers[i] = powers[i-1]*10;
    }
}

void solve(){
    int n; cin >> n;
    int len = 1, cnt = 9;
    while(n > len*cnt){
        n -= len*cnt;
        len++;
        cnt *= 10;
    }

    int start = powers[len-1];
    int index = (n-1)/len;
    int val = start + index;

    string s = to_string(val);
    int tot = 0, pref = 0;
    for(int i = 0; i < len; i++){
        int d = s[i]-'0';
        int remlen = len - i - 1;

        //soma dos digitos de 0 ate (d-1) * qtd de vezes q aparecem
        int var = ((d*(d-1))/2)*powers[remlen];
        //quanto q o prefixo ajuda
        int prefixo = d*powers[remlen]*pref;

        tot += var + prefixo;

        //nn estamos nas unidades
        if(remlen > 0){
            //soma das medidades menores de 00 ate X99
            tot += 45*remlen*powers[remlen-1]*d;
        }

        pref += d;
    }

    int dpos = (n-1)%len;
    for(int i = 0; i <= dpos; i++) tot += (s[i]-'0');

    cout << tot << endl;
}

signed main(){
	fastio;
    pten();
    int t; cin >> t;
	while(t--){
		solve();
	}
}