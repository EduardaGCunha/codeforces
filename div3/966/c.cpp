#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];

        int q; cin >> q;
        while(q--){
            string s; cin >> s;
            if(s.size() != n){
                cout << "NO\n";
                continue;
            }
            unordered_map<char, int> m1;
            unordered_map<int, char> m2;
            string ans = "YES";
            for(int i = 0; i < s.size(); i++){
                int x = arr[i];
                char c = s[i];
                if(!m1.count(c)) m1[c] = x;
                if(!m2.count(x)) m2[x] = c;
                if(m1[c] != x || m2[x] != c) {
                    ans = "NO";
                    break;
                }
            }
            cout << ans << endl;
        }
    }
}