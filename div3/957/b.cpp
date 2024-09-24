#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k, x; cin >> n >> k;
        int mx = 0;

        for(int i = 1; i <= k; i++){
            cin >> x;
            mx = max(mx, x);
        }

        cout << (n-mx)*2 - k+1 << endl;
    }
}