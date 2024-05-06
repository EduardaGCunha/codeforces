#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        string a, b; cin >> a >> b;
        int j = 0, res = 0;
        for(int i = 0; i < m && j < n; ++i){
            if(b[i] == a[j]){
                ++j;
                res++;
            }
        }
        cout << res << endl;
    }

}