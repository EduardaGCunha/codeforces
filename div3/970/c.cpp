#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;

        int prev = a;
        int cnt = 0;
        for(int i = a; i <= b; i += cnt){
            cnt++;
        }
        cout << cnt << endl;
    }
}