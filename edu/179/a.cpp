#include <bits/stdc++.h>
using namespace std; 

#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        int l = 63 - __builtin_clzll(x);
        cout << (2*l + 3) << endl;
    }
}