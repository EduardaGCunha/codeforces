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

        int m; cin >> m;
        for(int i = 0; i < m; i++){
            string s; cin >> s;
            string ans = "YES";
            unordered_map<char, int> mp;
            unordered_map<int, char> mp2;
            if(s.size() != n){
                ans = "NO";
                continue;
            } 
            for(int j = 0; j < s.size(); j++){
                if(mp.find(s[j]) == mp.end() && mp2.find(arr[j]) == mp2.end()){
                    mp[s[j]] = arr[j];
                    mp2[arr[j]] = s[j];
                }
                else if(mp[s[j]] != arr[j] && mp2[arr[j]] != s[j]){
                    ans = "NO";
                    break;
                }
            }
            cout << ans << endl;
        }
    }
}