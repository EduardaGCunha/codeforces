#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = 0, m = 0;
        for(int i = 1; i < n; i++){
            if(gcd(n, i) + i > m){
                ans = i;
                m = gcd(n, i) + i;
            }
        }
        cout << ans << endl;
    }
}