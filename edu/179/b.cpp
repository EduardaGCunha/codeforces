#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;
int fib[MAXN];

void solve(){
    int n, m; cin >> n >> m;
    //cout << fib[n-1] << " " << fib[n] << endl;
    string ans;
    for(int i = 0; i < m; i++){
        int w, l, h; cin >> w >> l >> h;
        if(l >= fib[n-1] && w >= fib[n-1] && h >= fib[n]) ans += "1";
        else if(w >= fib[n-1] && h >= fib[n-1] && l >= fib[n]) ans += "1"; 
        else if(h >= fib[n-1] && l >= fib[n-1] && w>= fib[n]) ans += "1";
        else ans += "0";
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    fib[0] = 1;
    fib[1] = 2;
    for(int i = 2; i <= 10; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    while(t--){
        solve();
    }
}