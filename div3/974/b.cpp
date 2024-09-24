#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int x = ((n+1)*n)/2 - (n-k)*(n-k+1)/2;
        if(x&1) cout << "NO" << endl;
        else cout << "YES" << endl;

    }
} 