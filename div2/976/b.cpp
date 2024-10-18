#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        int l = 1, r = 2e18, ans = 0;

        while(l <= r){
            int mid = (l+r)/2;
            int x = sqrt(mid);
            while(x*x > mid) x--;
            while((x+1) * (x+1) <= mid) x++;

            int res = mid - x; 
            if(res >= k){
                ans = mid;
                //cout << r << endl;
                r = mid-1;
            }else l = mid + 1;
        }

        cout << ans << endl;
    }
}