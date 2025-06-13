#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int arr[n+1], ult[n+1], prox[n+1];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) ult[i] = n+2;

    for(int i = n; i >= 1; i--){
        prox[i] = ult[arr[i]];
        ult[arr[i]] = i;
    }

    // for(int i = n; i >= 1; i--){
    //     cout << prox[i] << " " << ult[i] << endl;
    // }

    int ans = 0, l = 1;
    while(l <= n){
        int r = l;
        //auemtno os lados
        while(true){
            int mx1 = 0; 
            for(int i = l; i <= r; i++){
                mx1 = max(mx1, prox[i]);
            }
            ans++;
            if(mx1 > n) break;
            l = r + 1;
            r = mx1;
            //cout << l << " " << r << endl;
        }
        break;
    }

    cout << ans << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
