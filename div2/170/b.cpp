#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
const int MOD = 1e9 + 7;

int calc(int b, int e){
    int ans = 1;
    while(e > 0){
        if(e&1) ans = (1LL * ans * b) % MOD;
        b = (1LL * b * b) % MOD;
        e /= 2;
    }
    return ans;
}

//nn da pra faze
// 5 3 8
//5 2 4
signed main() {
    fastio;
    int t; cin >> t;
    int n[t], k[t];
    for(int i = 0; i < t; i++) cin >> n[i];
    for(int i = 0; i < t; i++) cin >> k[i];

    for(int i = 0; i < t; i++){
        cout << calc(2, k[i]) << endl;
    }
}
