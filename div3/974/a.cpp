#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int cnt = 0, ans = 0;;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(x >= k){
                cnt += x;
            }else if(x == 0 && cnt > 0){
                cnt--;
                ans++;
            }
        }

        cout << ans << endl;
    }
}