#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int x, y, k; cin >> x >> y >> k;

    int qtdx = (x+k-1)/k;
    int qtdy = (y+k-1)/k;
    if(qtdx > qtdy) cout << qtdx+qtdx-1 << endl;
    else cout << qtdy+qtdy << endl;
}

signed main() {
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }

}
