#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, b, c; cin >> n >> b >> c;
        if(b == 0){
            if(c < n - 2) cout << -1 << endl;
            else if(c == n - 1 || c == n - 2) cout << n - 1 << endl;
            else cout << n << endl;
        }else{
            if(c >= n) cout << n << endl;
            else cout << n - max(0ll, 1 + (n - c - 1)/b) << endl;
        }
    }
}