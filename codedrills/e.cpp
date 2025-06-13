#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(!(x&1)) cnt++;
        }
        cout << (cnt)*(cnt-1)/2 << endl;
    }
}