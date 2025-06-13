#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int a; cin >> a;
        double x = (int) round(sqrt(a));

        if(1LL*x*x != a) cout << -1 << endl;
        else if(x == 1) cout << 1 << " " << 0 << endl;
        else if(x == 0) cout << 0 << " " << 0 << endl;
        else cout << x-1 << " " << 1 << endl;
    }
}