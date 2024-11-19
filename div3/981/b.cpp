#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                int a; cin >> a;
                if(a < 0){
                    m[j-i] = min(m[j-i], a);
                }
            }
        }

        int ans = 0;
        for(auto u : m) ans += -u.second;
        cout << ans << endl;
    }
}
