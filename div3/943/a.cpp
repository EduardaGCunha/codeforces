#include <bits/stdc++.h>
using namespace std;

#define int long long

// int check(int x){
//     if()
// }

signed main(){
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        int m = INT_MIN, res = 1;
        for(int i = 2; i < x; i++){
            if(gcd(x, i) + i > m){
                m = gcd(x, i) + i;
                res = i;
            }
        }
        cout << res << endl;
       
    }
}