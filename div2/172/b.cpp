#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n), visited(n);
        map<int, int> freq;
        for(int i = 0 ; i< n; i++){
            cin >> arr[i];
            freq[arr[i]]++;
        }

        int ans = 0, cnt = 0;
        for(auto u : freq){
            if(u.second == 1) cnt++;
            else{
                ans++;
            }
        }

        if(cnt&1) cout << ans + cnt+1 << endl;
        else cout << ans + cnt << endl;
    }
}