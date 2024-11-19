#include <bits/stdc++.h>
using namespace std;



int main(){
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int ans = INT_MAX;
        for(int i = a; i <= b; i++){
            ans = min(ans, (i-a) + (b-i));
        }
        if(ans == INT_MAX) ans = 0;
        cout << ans << endl;
    }
}