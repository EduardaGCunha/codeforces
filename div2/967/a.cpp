#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, int> m;
        int mx = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            m[x]++;
            mx = max(mx, m[x]);
        }

        cout << min(n-1, n-mx) << endl;

    }
}