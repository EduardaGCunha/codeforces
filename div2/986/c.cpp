#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, m, v; cin >> n >> m >> v;
    int sum[n+1], arr[n];
    sum[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum[i+1] = sum[i] + arr[i];
    }

    int pfx[m+1], mcnt = 1, cursum = 0;
    pfx[0] = -1;
    for(int i = 0; i < n; i++){
        if(mcnt > m) break;
        cursum += arr[i];
        if(cursum >= v){
            cursum = 0;
            pfx[mcnt] = i;
            mcnt++;
        }
    }

    if(mcnt != m+1){
        cout << -1 << endl;
        return;
    }

    int sfx[m+1];
    sfx[0] = n;
    mcnt = 1, cursum = 0;
    for(int i = n-1; i >= 0; i--){
        if(mcnt > m) break;
        cursum += arr[i];
        if(cursum >= v){
            cursum = 0;
            sfx[mcnt] = i;
            mcnt++;
        }
    }

    if(mcnt != m+1){
        cout << -1 << endl;
        return;
    }


    int ans = 0;
    for(int i = 0; i < m+1; i++){
        if(pfx[i] < sfx[m-i]){
            ans = max(ans, sum[sfx[m-i]] - sum[pfx[i]+1]);
        }
    }

    cout << ans << endl;
    

    // int i = 1, j = 1, mcnt = 0, ans = 0;
    // while(j <= n){
    //     if(prefix[j] - prefix[i-1] >= v){
    //         mcnt++;
    //         ans = max(ans, prefix[j]-prefix[i-1]);
    //         i = j;
    //     }
    //     if(mcnt == m) break;
    //     j++;
    // }
    // if(mcnt < m){
    //     cout << -1 << endl;
    // }else{
    //     ans = max(ans, prefix[n]-prefix[j-1]);
    //     cout << ans << endl;
    // }
}

signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}