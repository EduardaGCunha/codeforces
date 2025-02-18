#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
int low = INT_MAX;
int n, k;

int sum(int l, int r, int qtd){
   return qtd*(l + r)/2;
}

void solve(){
    cin >> n >> k;

    int l = 1, r = n;
    int ans = LLONG_MAX;
    while(l <= r){
        int mid = (l+r)/2;
        //cout << mid << " " << k+mid-1 << " " << k+mid << " " << k+n-1 << endl;
        int a = sum(k, k+mid-1, mid);
        int b = sum(k+mid, k+n-1, n-mid);
        if(a == b){
            cout << 0 << endl;
            return;
        }
        ans = min(ans, abs(b-a));
        if(a < b) l = mid+1;
        else r = mid-1;
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