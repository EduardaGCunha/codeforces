#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e5+1;
int pfx[MAXN], pfxn[MAXN];

signed main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(arr[i] > 0) pfx[arr[i]] = x;
        else pfx[abs(arr[i])] = x;
    }

    for(int i = 1; i <= MAXN; i++){
        pfx[i] += pfx[i-1];
    }

    for(int i = MAXN-1; i >= 0; i--){
        pfx[i] += pfx[i+1];
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << pfx[r] - pfx[l-1] << endl;
    }
}