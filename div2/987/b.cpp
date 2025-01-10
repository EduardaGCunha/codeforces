#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string ans = "YES";
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        if(abs(i-a) > 1){
            ans = "NO";
        }
    }
   
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}